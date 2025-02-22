class Solution {
public:
    // 그냥 최소 값을 찾고 싶다면 그냥 하던대로 다익스트라 하면 되는데, 최대 중에 최소를 찾고 싶다면 조금 다르게 해야 한다
    // 여기서는 이번에 생성한 값이랑 지금 자기가 가지고 있는 최대 값을 비교해서 최대인 놈을 가지고 해야 했다

    // 최대 중 최소 구하려면 x = func() 으로 x를 구하고 이거랑 현재 dist[cur] 랑 비교해서 둘 중 max를 찾은다음에 그 값을 x로 사용해야 한다 
    // 이래야지 지금까지의 최대값이 유실이 안된다.

    // 그러므로 여기서 하는 다익스트라는 어떻게 보면 지금 당장의 edge의 최소를 비교하고자 하는게 아니라, 지금까지의 경로의 최소 값을 구하고자 하는 것이기 때문에다
    // 마치 최단 거리를 구하는 것이 '지금까지의 경로의 합이' x로 표현 되고, 이 값과 destination을 같이 queue에 넣었다면
    // 경로중에 최대는 '지금까지의 경로 중 최대값'을 x로 표현하고 이 값을 destination과 qeuueu에 넣는 것이다

    // 그러므로 최단 거리 문제는 dist[cur] + x 였던 것이고, 경로중 최대 값 은 max(dist[cur] , x) 인 것이다.

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

