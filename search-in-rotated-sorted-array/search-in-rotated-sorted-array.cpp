class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
            {
                return mid;
            }else
            {
                if(nums[mid] >= nums[left])
                {
                    // 이건 왼쪽이 정렬 되어 있다

                    if(nums[left] <= target && target < nums[mid])
                    {
                        right = mid -1;
                    }else
                    {
                        left = mid + 1;
                    }
                }else
                {
                    // 오른쪽 정렬
                    if(nums[mid] < target && target <= nums[right])
                    {
                        left = mid + 1;
                    }else
                    {
                        right = mid -1;
                    }
                }
            }
        }

        return -1;
    }
};