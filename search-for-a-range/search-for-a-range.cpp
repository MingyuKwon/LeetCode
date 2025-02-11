class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 이건 그냥 타겟 보다 작은 놈 중에 최고, 타겟 보다 큰 놈 중에 최대를 구하고 범위를 좁히면 될 거 같은데
        int n = nums.size();
        vector<int> ans;

        if(n == 0) return {-1,-1};
        
        int left = 0;
        int right = n-1;

        while(left < right)
        {
            int mid = left + (right - left)/2;
            
            if(nums[mid] >= target)
            {
                right = mid;
            }else
            {
                left = mid + 1;
            }
        }

        if(nums[left] != target) return {-1,-1};
        ans.push_back(left);

        left = 0;
        right = n-1;

        while(left + 1 < right)
        {
            int mid = left + (right - left)/2;
            
            if(nums[mid] <= target)
            {
                left = mid;
            }else
            {
                right = mid - 1;
            }
        }

        if(nums[right] == target)
        {
            ans.push_back(right);
        }else
        {
            ans.push_back(left);
        }

        return ans;

    }
};