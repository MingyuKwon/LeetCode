class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // 핵심은, 추가 간격 보다 전혀 상관 없는 범위들은 답에 넣고, 상관 있는 범위 들은 싹다 고려해서 
        // 추가 간격을 그들을 모두 포함하는 범위로 확장하고 추가하고
        // 남은 범위를 다 추가한다
        int n = intervals.size(), i = 0;
        vector<vector<int>> res;
        //case 1: no overlapping case before the merge intervals
		//compare ending point of intervals to starting point of newInterval
        while(i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }                           
		//case 2: overlapping case and merging of intervals
        while(i < n && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        // case 3: no overlapping of intervals after newinterval being merged
        while(i < n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;



        //============================ 간격 넣은 다음에 정렬 후에 합치기 ============================
        // 새로운 범위의 끝점 보다 시작점이 큰 경우 제외
        // 새로운 범위의 시작점 보다 끝 점이 작은 경우 제외

        //  그럼 처음 리스트를 뒤져 보다가, 주어진 범위의 시작점보다 끝 점이 크거나 같은 경우 그 범위와 주어진 범위를 합친다
        // 그런 후에, 자신 뒤의 범위들을 뒤져 보면서 합치기를 반복한다. 그러다 다음 범위와 합치기가 안되는 순간에 멈춤
        // vector<vector<int>> result;

        // intervals.push_back(newInterval);
        // sort(intervals.begin(),intervals.end());

        // int currentResultIndex = 0;
        // result.push_back(intervals[0]);

        // for(int i=1; i<intervals.size(); i++)
        // {
        //     if(result[currentResultIndex][1] < intervals[i][0]) // 새로운 범위 추가 해야할 때
        //     {
        //         result.push_back(intervals[i]);
        //         currentResultIndex++;
        //     }else
        //     {
        //         result[currentResultIndex][0] = min(result[currentResultIndex][0] , intervals[i][0]);
        //         result[currentResultIndex][1] = max(result[currentResultIndex][1] , intervals[i][1]);
        //     }
        // }

        // return result;
    }
};