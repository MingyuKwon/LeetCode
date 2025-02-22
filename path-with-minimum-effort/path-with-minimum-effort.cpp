class Solution {
public:
    // 아 시발 그냥 표시를 100 * row + y 이렇게 하자
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int columns = heights[0].size();

        // 아 그러니까 이동했을 때 두 차이 간격의 최대 값이 최소가 되는 놈을 찾고 싶다는거지?

        vector<vector<int>> minHeight(rows, vector<int>(columns, INT_MAX));
        minHeight[0][0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        vector<int> direcRow = {1, 0, -1, 0};
        vector<int> direcCol = {0, 1, 0, -1};

        while(!pq.empty())
        {
            auto[height, point] = pq.top();
            pq.pop();
            int pointRow = point / 100;
            int pointCol = point % 100;

            if(minHeight[pointRow][pointCol] < height) continue;

            for(int i=0; i<4; i++)
            {
                int nextRow = pointRow + direcRow[i];
                int nextCol = pointCol + direcCol[i];

                if(nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= columns) continue;

                int effort = abs(heights[nextRow][nextCol] - heights[pointRow][pointCol]);
                int maxDiff = max(effort, minHeight[pointRow][pointCol]);

                if(maxDiff < minHeight[nextRow][nextCol])
                {
                    minHeight[nextRow][nextCol] = maxDiff;
                    pq.push({effort, nextRow * 100 + nextCol});
                }
            }
        }

        return minHeight[rows-1][columns-1];

    }
};

