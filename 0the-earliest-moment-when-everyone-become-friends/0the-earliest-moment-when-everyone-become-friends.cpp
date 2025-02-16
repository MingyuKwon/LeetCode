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

        bool unionSet(int x, int y)
        {
            int rootX = find(x);
            int rootY = find(y);

            if(rootX != rootY)
            {
                root[rootY] = rootX;
            }

            return isAllConnected();
        }

        bool isAllConnected()
        {
            int count = 0;

            for(int i=0; i<root.size(); i++)
            {
                if(root[i] == i) count++; 
            }

            return count == 1;
        }

    private:
        vector<int> root;
    };

    int earliestAcq(vector<vector<int>>& logs, int n) {
        // 아 그러니까 연결되어 있어야 한다는 거구나
        JointSet ans(n);

        sort(logs.begin(), logs.end());

        for(vector<int> log : logs)
        {
            if(ans.unionSet(log[1], log[2])) return log[0];
        }

        return -1;
    }
};