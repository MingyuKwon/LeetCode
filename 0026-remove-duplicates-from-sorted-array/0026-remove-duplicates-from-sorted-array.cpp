class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> HASH_MAP; 

        for(int i=0; i<nums.size(); i++)
        {
            if(HASH_MAP.find(nums[i]) != HASH_MAP.end())
            {
                nums.erase(nums.begin() + i);
                i--;
            }else
            {
                HASH_MAP[nums[i]] = 0;
            }
        }

        return nums.size();

    }
};