class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> hashMap;

        for(int I : nums)
        {
            if(hashMap.find(I) == hashMap.end())
            {   
                hashMap[I] = 1;
            }else
            {
                hashMap[I] = 2;
            }
            
        }

        for(auto a : hashMap)
        {
            if(a.second == 1) return a.first;
        }

        return 0;
    }
};