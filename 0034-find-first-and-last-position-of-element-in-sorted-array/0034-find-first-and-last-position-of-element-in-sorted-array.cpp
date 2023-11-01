class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1;
        int end = -1;
        
        int left = 0;
        int right = nums.size()-1;
        int mid = left + (right - left)/2;

        while(left <= right)
        {
            mid = left + (right - left)/2;
            if(nums[mid] == target && (mid == 0 || nums[mid-1] != nums[mid]))
            {
                start = mid;
                break;
            }
            // target이 mid보다 작음
            // 큼
            // 같은데 왼쪽과 같음

            if(nums[mid] < target)
            {
                left = mid + 1;
            }else 
            {
                right = mid - 1;
            }
        }

        left = 0;
        right = nums.size()-1;
        mid = left + (right - left)/2;

        while(left <= right)
        {
            mid = left + (right - left)/2;
            if(nums[mid] == target && (mid == nums.size()-1 || nums[mid+1] != nums[mid]))
            {
                end = mid;
                break;
            }
            // target이 mid보다 작음
            // 큼
            // 같은데 오른과 같음

            if(nums[mid] > target)
            {
                right = mid - 1;
            }else 
            {
                left = mid + 1;
            }
        }

        return {start, end};
    }
};