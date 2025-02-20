class Solution {
public:
    // 크루스칼은 edge를 기준으로 하는거고, prim은 node 기준이다
    // 그리고 spanning tree에서 edge는 n-1개 이고, node는 n개이다
    
    // 일단 해보니까 구현은 prim이 좀더 쉬운거 같다
    // 일반 bfs나 dfs를 반복으로 돌리는 것 같은데, 컨테이너로 priority queue를 쓰는 느낌이다

    // 그리고 node 중심이어서 상대적으로 구현하기도 편하고, 직관적이다
    // pq에다가 거리와 목적지만 넣는 것으로 edge 표현하는게 인상 깊었다

    // kruskal이었으면 시작점과 목적지 둘다 표시하고 unionSet까지 만들었어야 할 텐데
    // prim이 구현은 더 편한 것 같기도 하고

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        

        vector<bool> seen(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0,0});
        
        int mstCost = 0;
        int count = n;

        while(!pq.empty())
        {
            auto[distance, current] = pq.top();
            pq.pop();

            if(seen[current]) continue;

            seen[current] = true;
            mstCost += distance;
            count--;

            if(count == 0) break;

            for(int i=0; i<n; i++)
            {
                if(!seen[i])
                {
                    int xGap = abs(points[i][0] - points[current][0]);
                    int yGap = abs(points[i][1] - points[current][1]);
                    pq.push({xGap + yGap,i});
                }
            }
            
        }
        
        return mstCost;
    }
};