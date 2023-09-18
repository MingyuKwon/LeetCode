class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> HASHMAP;

        for(int i=0; i<nums.size(); i++)
        {
            int firstNum = nums[i];
            int secondNum = target - nums[i];

            if(HASHMAP.count(secondNum))
            {
                return {i, HASHMAP[secondNum]};
            }

            HASHMAP[nums[i]] = i;
        }

        return {};

        
    }
};