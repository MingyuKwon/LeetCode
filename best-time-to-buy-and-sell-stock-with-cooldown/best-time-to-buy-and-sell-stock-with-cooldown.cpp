class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n ,vector<int>(2, INT_MIN / 2));

        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for(int i=1; i<n; i++)
        {
            // 파는건 상관인 없는데 사려면 팔고 나서 1일 후에 사야 한다

            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);

            if(i == 1) 
            {
                dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
            }else
            {
                dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
            }
            
        }

        return dp[n-1][0];
    }
};