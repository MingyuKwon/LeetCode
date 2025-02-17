class Solution {
public:
    class JointSet
    {
        public:
            pair<string, double> find(string str)
            {
                if(root[str].first == str) return root[str];

                pair<string, double> rootNode = find(root[str].first);
                root[str].first = rootNode.first;
                root[str].second = rootNode.second * root[str].second;

                return root[str];
            }

            void unionSet(string x, string y, double value)
            {
                if(root.count(x) == 0) root[x] = {x, 1};
                if(root.count(y) == 0) root[y] = {y, 1};

                pair<string, double> rootX = find(x);
                pair<string, double> rootY = find(y);

                if(rootX.first != rootY.first)
                {
                    root[rootX.first].first = rootY.first;
                    root[rootX.first].second = value * rootY.second / rootX.second ;
                }
            }
            
            double query(string x, string y)
            {
                
                if(root.count(x) == 0) return -1;
                if(root.count(y) == 0) return -1;

                pair<string, double> rootX = find(x);
                pair<string, double> rootY = find(y);

                if(rootX.first != rootY.first) return -1;

                return rootX.second / rootY.second;

            }
            
        private:
            unordered_map<string, pair<string, double>> root; 
    };

    // 그래프를 노드와 엣지가 있는 걸로만 생각하지 말고, '관계'를 엣지로 보게되면 아주 시야가 넓어진다
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        JointSet joinSet;
        int n = equations.size();

        vector<double> ans;
        
        for(int i=0; i<n; i++)
        {
            joinSet.unionSet(equations[i][0], equations[i][1], values[i]);
        }
        
        for(int i=0; i<queries.size(); i++)
        {
            ans.push_back(joinSet.query(queries[i][0] , queries[i][1]));
        }

        return ans;
    }
};