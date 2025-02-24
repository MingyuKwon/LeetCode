class Solution {
public:
    int climbStairs(int n) {
        // 숫자는 딱 맞춰야 함
        
        vector<int> dp(n+1, 1);
        
        for(int i=2; i<=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};