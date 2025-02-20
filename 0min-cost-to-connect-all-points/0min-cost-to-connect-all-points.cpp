class Solution {
public:

    class UnionFind
    {
        public:
            UnionFind(int n)
            {   
                for(int i=0; i<n; i++)
                {
                    root.push_back(i);
                }
            }
            
            int find(int x)
            {
                if(root[x] == x) return x;
                return root[x] = find(root[x]);
            }

            bool join(int x, int y)
            {
                int rootX = find(x);
                int rootY = find(y);

                if(rootX != rootY)
                {
                    root[rootY] = rootX;
                    return true;
                }else
                {
                    return false;
                }
            }


        private:
            vector<int> root;
    };

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        int n = points.size();

        int ans = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int xGap = abs(points[i][0] - points[j][0]);
                int yGap = abs(points[i][1] - points[j][1]);
                int length = xGap + yGap;

                edges.push_back({length, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        int count = n-1;
        UnionFind uf(n);

        for(vector<int> edge : edges)
        {
            int distance = edge[0];
            int node1 = edge[1];
            int node2 = edge[2];

            if(uf.join(node1, node2))
            {
                count--;
                ans += distance;
            }

            if(count == 0) break;

        }

        return ans;
    }
};