class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hashMap;

        for(int a : nums)
        {
            if(hashMap.find(a) == hashMap.end())
            {
                hashMap[a] = 0;
            }else
            {
                return true;
            }
        }

        return false;
    }
};