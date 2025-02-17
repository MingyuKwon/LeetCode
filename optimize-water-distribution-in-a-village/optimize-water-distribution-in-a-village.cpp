class Solution {
public:
    class JointSet
    {
        public:
            int ans = 0;

            JointSet(vector<int>& _wells)
            {
                wells = _wells;
                for(int i=0; i<wells.size(); i++)
                {
                    root.push_back(i);
                    ans += wells[i];
                }
            }

            int find(int x)
            {
                if(root[x] == x) return root[x];
                return root[x] = find(root[x]);
            }

            void unionSet(int x, int y, int value)
            {
                int rootX = find(x-1);
                int rootY = find(y-1);

                if(rootX != rootY)
                {
                    int rootXCost = wells[rootX];
                    int rootYCost = wells[rootY];

                    int maxCost = max(rootXCost, rootYCost);

                    if(maxCost > value)
                    {
                        if(rootXCost <= rootYCost)
                        {   
                            root[rootY] = rootX;
                            ans -= rootYCost;
                            ans += value;
                        }else
                        {
                            root[rootX] = rootY;
                            ans -= rootXCost;
                            ans += value;
                        }
                    }
                }
            }

        private:
            vector<int> root;
            vector<int> wells;
    };

    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        // 우물 하나 두고, 모두 연결되게 이을 수도 있고, 그냥 새로운 우물을 파고 그 주변만 모을 수도 있다

        // 우물의 위치가 고정된게 아닉 ㅗ여러 개일 수 있는데 이걸 일일히 다 해봐야 하나>
        // 아니면 전체를 다 우물판다고 가정하고, 가능하면 선을 이을까?

        // 문제가 그냥 다 연결하면 되기 때문에 얼마나 길어지는것과는 상관 없이 연결만 하면 된다

        // 처음에는 값을 다 가지고 있어야 한다

        // 이러면 기존 우물일 수록 오히려 값이 커야 하나?
        
        JointSet joinSet(wells);
        sort(pipes.begin(), pipes.end(), [](const vector<int>& left, const vector<int>& right)
        {
            return left[2] < right[2];
        });

        for(vector<int> pipe : pipes)
        {
            joinSet.unionSet(pipe[0], pipe[1], pipe[2]);
        }

        return joinSet.ans;
    }
};