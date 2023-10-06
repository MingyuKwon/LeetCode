class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int SIZE = nums.size();

        int sum = 0;
        for(int i=1; i<SIZE+1; i++)
        {   
            sum += i;
        }

        for(int i : nums)
        {
            sum -= i;
        }

        return sum;
    }
};