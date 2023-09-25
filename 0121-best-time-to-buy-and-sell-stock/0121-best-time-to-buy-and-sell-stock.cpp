class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int vecSize = prices.size();
        int DP[vecSize + 1];
        int smallest = 10000;

        for(int& a : DP)
        {
            a = 0;
        }

        for(int i=1; i<=vecSize; i++)
        {
            if(prices[i-1] < smallest)
            {
                smallest = prices[i-1];
                DP[i] = DP[i-1];
            }else
            {
                DP[i] = max(DP[i-1], prices[i-1] - smallest);
            }
        }

        return DP[vecSize];
    }
};