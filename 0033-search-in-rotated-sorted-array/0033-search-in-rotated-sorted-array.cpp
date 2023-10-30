class Solution {
public:
    int search(vector<int>& nums, int target) {
        int numSize = nums.size();
        if(numSize == 1) return (nums[0] == target) ? 0 : -1; 

        int left = 0;
        int right = nums.size()-1;
        int mid = left + (right - left)/2;

        while(left < right)
        {
            mid = left + (right - left)/2;
            if(nums[right] < nums[mid])
            {
                left = mid+1;
            }else
            {
                right = mid;
            }
        }


        int pivot = left;

        left = 0;
        right = numSize-1;
        mid = left + (right - left)/2;

        
        while(left <= right)
        {
            mid = left + (right - left)/2;
            if(target > nums[(mid + pivot) % numSize])
            {
                left = mid + 1;
            }else if(target < nums[(mid + pivot) % numSize])
            {
                right = mid - 1;
            }else
            {
                return (mid + pivot) % numSize;
            }
        }

        return -1;
    }

};