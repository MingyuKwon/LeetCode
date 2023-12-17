class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // 새로운 범위의 끝점 보다 시작점이 큰 경우 제외
        // 새로운 범위의 시작점 보다 끝 점이 작은 경우 제외

        //  그럼 처음 리스트를 뒤져 보다가, 주어진 범위의 시작점보다 끝 점이 크거나 같은 경우 그 범위와 주어진 범위를 합친다
        // 그런 후에, 자신 뒤의 범위들을 뒤져 보면서 합치기를 반복한다. 그러다 다음 범위와 합치기가 안되는 순간에 멈춤
        vector<vector<int>> result;

        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());

        int currentResultIndex = 0;
        result.push_back(intervals[0]);

        for(int i=1; i<intervals.size(); i++)
        {
            if(result[currentResultIndex][1] < intervals[i][0]) // 새로운 범위 추가 해야할 때
            {
                result.push_back(intervals[i]);
                currentResultIndex++;
            }else
            {
                result[currentResultIndex][0] = min(result[currentResultIndex][0] , intervals[i][0]);
                result[currentResultIndex][1] = max(result[currentResultIndex][1] , intervals[i][1]);
            }
        }

        return result;
    }
};