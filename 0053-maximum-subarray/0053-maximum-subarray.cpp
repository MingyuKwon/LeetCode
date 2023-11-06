class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> DP(nums.size()+1, INT_MIN);

        for(int i=1; i<=nums.size(); i++)
        {
            if(DP[i-1] < 0)
            {
                DP[i] = nums[i-1];
            }else
            {
                DP[i] = DP[i-1] + nums[i-1];
            }
        }

        int MAX = INT_MIN;
        for(int i : DP)
        {
            if(MAX < i) MAX = i;
        }

        return MAX;
    }
};