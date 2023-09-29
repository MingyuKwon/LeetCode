class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int numSize = nums.size();
        unordered_map<int, int> hashMap;
        for(int i=0; i<numSize; i++)
        {
            if(hashMap.find(nums[i]) != hashMap.end() && abs(hashMap[nums[i]] - i) <= k )
            {
                return true;
            }      

            hashMap[nums[i]] = i;
        }

        return false;
    }
};