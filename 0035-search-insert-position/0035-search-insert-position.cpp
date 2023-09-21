class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int arraysize = nums.size();
        
        int min = 0;
        int max = arraysize -1;
        int mid = 0;
        
        while(min <= max)
        {
            mid = ( min + max ) / 2;
            
            if(nums[mid] == target)
            {
                return mid;
            }else
            {
                if(nums[mid] > target)
                {
                    max = mid - 1;
                }else
                {
                    min = mid + 1;
                }
            }
        }
        
        return min;
        
    }
};