class Solution {
public:
    class JointSet
    {
    public:
        JointSet(int n)
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

        void unionSet(int x, int y)
        {
            int rootX = find(x);
            int rootY = find(y);

            if(rootX == rootY) return;

            root[rootY] = rootX;
        }

        int province()
        {
            int count = 0;
            for(int i=0; i<root.size(); i++)
            {
                if(root[i] == i) count++;
            }
            return count;
        }
    private:
        vector<int> root;
    };

    int countComponents(int n, vector<vector<int>>& edges) {
        JointSet ans(n);
        for(auto edge : edges)
        {
            ans.unionSet(edge[0], edge[1]);
        }
        return ans.province();
    }
};