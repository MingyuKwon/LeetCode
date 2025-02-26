class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;

        combine(ans, comb, n, k);
        return ans;
    }

    void combine(vector<vector<int>>& ans, vector<int>& comb, int n, int k)
    {
        if(k == 0) 
        {
            ans.push_back(comb);
            return;
        }

        int startVal = 0;
        if(!comb.empty()) startVal = comb.back();

        for(int i = startVal + 1; i <= n; i++)
        {
            comb.push_back(i);
            combine(ans, comb, n, k-1);
            comb.pop_back();
        }


    }
};