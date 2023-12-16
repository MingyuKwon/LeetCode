class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        // 그렇게 정한 시작점, 끝점을 한 벡터에 다 몰아두고 그 사이들에서 범위를 뽑아내면 된다
        // 시작점 위치에 -1을, 끝점 위치에 1을 더해서 저장한다
        // 그리고 그렇게 확정 된 배열을 시작점 만나면 -1, 끝점 만나면 1을 더하다가 0이 되면 그떄 범위 확정

        vector<int> startindex(10001,0);
        vector<int> endindex(10001,0);
        for(vector<int> n : intervals)
        {
            startindex[n[0]]--;
            endindex[n[1]]++;
        }

        int isZeroCount = 0;
        for(int i=0; i<=10000; i++)
        {
            // 둘다 0이면 그냥 아에 표기가 안되는 거임
            if(startindex[i] == 0 && endindex[i] == 0) 
            {
                continue;
            }else
            {
                int previousIsZeroCount = isZeroCount;
                int checkValue = startindex[i] + endindex[i];
                isZeroCount += checkValue;

                // 이전에 0인 경우엔, 시작점이 등장한다. 
                if(previousIsZeroCount == 0)
                {
                    // 시작점이 등장하고, 끝점은 나오지 않은 경우
                    if(checkValue != 0)
                    {
                        vector<int> newVector(1,i);
                        result.push_back(newVector);
                    }else  // 시작점과 끝점이 동시에 나온 경우
                    {
                        vector<int> newVector(2,i);
                        result.push_back(newVector);
                    }
                    
                }else if(isZeroCount == 0) // 이 경우, 합져저서 0이 된 경우이므로 끝점임
                {
                    result[result.size()-1].push_back(i);
                }                
        
            }
        }
        return result;
    }
};