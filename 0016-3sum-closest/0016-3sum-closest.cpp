class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 30000;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-2; i++)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if(target - sum < 0)
                {
                    right--;
                }else if(target - sum > 0)
                {
                    left++;
                }else
                {
                    return sum;
                }

                if(abs(target - sum) < abs(target - ans)) ans = sum;
            }
        }

        return ans;

    }
};