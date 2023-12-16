//Comment and Upvote

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        vector<vector<int>> result;
        //base case when threr are no intervals
        if(interval.size()==0)return result;
        //sort takes O(nlogn) time
        // 벡터의 벡터를 sort하면, 첫번쨰 인자를 기준으로 마치 문자열 사전식 sort하듯이 해준다
        sort(interval.begin(),interval.end());
        // 이렇게 되면 범위의 시작점은 다 오름차순이 되므로 순서대로 범위 안에 들어가는지 아닌지 확인하면 된다
        //insert the the the first interval in the result
        result.push_back(interval[0]);
        int j=0;
        //Traverse the whole vector .Takes O(n) time
        for(int i=1;i<interval.size();i++)
        {
            //if intevals are overlapping
            if(result[j][1]>=interval[i][0]) result[j][1]=max(result[j][1],interval[i][1]);
            //else they are not overlapping
            else
            {
                j++;
                result.push_back(interval[i]);
            }
        }
        return result;
    }
    
    
// =============== 아래는 시간복잡도가 n인 대신에, 기본 10000을 도는 것이 기본이라서 n이 작으면 시간 상에서 불리 =======
    
    // public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int>> result;
//         // 그렇게 정한 시작점, 끝점을 한 벡터에 다 몰아두고 그 사이들에서 범위를 뽑아내면 된다
//         // 시작점 위치에 -1을, 끝점 위치에 1을 더해서 저장한다
//         // 그리고 그렇게 확정 된 배열을 시작점 만나면 -1, 끝점 만나면 1을 더하다가 0이 되면 그떄 범위 확정

//         vector<int> startindex(10001,0);
//         vector<int> endindex(10001,0);
//         for(vector<int> n : intervals)
//         {
//             startindex[n[0]]--;
//             endindex[n[1]]++;
//         }

//         int isZeroCount = 0;
//         for(int i=0; i<=10000; i++)
//         {
//             // 둘다 0이면 그냥 아에 표기가 안되는 거임
//             if(startindex[i] == 0 && endindex[i] == 0) 
//             {
//                 continue;
//             }else
//             {
//                 int previousIsZeroCount = isZeroCount;
//                 int checkValue = startindex[i] + endindex[i];
//                 isZeroCount += checkValue;

//                 // 이전에 0인 경우엔, 시작점이 등장한다. 
//                 if(previousIsZeroCount == 0)
//                 {
//                     // 시작점이 등장하고, 끝점은 나오지 않은 경우
//                     if(checkValue != 0)
//                     {
//                         vector<int> newVector(1,i);
//                         result.push_back(newVector);
//                     }else  // 시작점과 끝점이 동시에 나온 경우
//                     {
//                         vector<int> newVector(2,i);
//                         result.push_back(newVector);
//                     }
                    
//                 }else if(isZeroCount == 0) // 이 경우, 합져저서 0이 된 경우이므로 끝점임
//                 {
//                     result[result.size()-1].push_back(i);
//                 }                
        
//             }
//         }
//         return result;
//     }}


};


