class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> HashMap;

        for(int I : nums1)
        {
            HashMap[I]++;
        }

        for(int I : nums2)
        {
            if(HashMap[I] > 0) 
            {
                HashMap[I] = 0;
                result.push_back(I);
            }
        }

        return result;
    }
};