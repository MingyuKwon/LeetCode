class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string comb;
        solve(ans, comb, n, 0, 0);
        return ans;
    }

    void solve(vector<string>& ans, string& comb, int n, int openN, int closeN)
    {
        if(closeN == n)
        {
            ans.push_back(comb);
            return;
        }

        bool bOpenEnable = openN < n;
        bool bCloseEnable = closeN < n && openN > closeN;

        if(bOpenEnable)
        {
            comb += '(';
            solve(ans, comb, n, openN + 1, closeN);
            comb.pop_back();
        }

        if(bCloseEnable)
        {
            comb += ')';
            solve(ans, comb, n, openN, closeN+1);
            comb.pop_back();
        }
    }
};