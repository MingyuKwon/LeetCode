class Solution {
public:

    class UnionSet
    {
    public:
        UnionSet(int n)
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

            if(rootX != rootY)
            {
                root[rootY] = rootX;
            }
        }

        string swapAns(string s)
        {
            unordered_map<int, vector<char>> rootHash;
            for(int i=0; i<s.size(); i++)
            {
                rootHash[find(i)].push_back(s[i]);
            }

            for(auto& tmep : rootHash)
            {
                sort(tmep.second.begin(), tmep.second.end(), greater<char>());
            }

            string ans = "";
            for(int i=0; i<s.size(); i++)
            {
                ans += rootHash[find(i)].back();
                rootHash[find(i)].pop_back();
            }

            return ans;
        }

    private:
        vector<int> root;
    };

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        UnionSet ans(n);

        for(vector<int> pair : pairs)
        {
            ans.unionSet(pair[0], pair[1]);
        }

        return ans.swapAns(s);
    }
};