class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int SIZE = nums.size();
        int index = 0;
        int zeroindex = SIZE;

        while(index < zeroindex)
        {
            if(nums[index] == 0)
            {
                nums.push_back(0);
                nums.erase(nums.begin() + index);
                zeroindex--;
                continue;
            }

            index++;
        }
    }
};