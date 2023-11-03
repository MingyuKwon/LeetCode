class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> DP(nums.size()+1, 10000);
        DP[1] = 0;
        for(int i=1; i<=nums.size(); i++)
        {
            int N = nums[i-1];
            for(int k=1;i+k <= nums.size() && k<=N; k++)
            {
                DP[i+k] = min(DP[i+k], DP[i] +1);
            }
        }

        return DP[nums.size()];
    }

    
};