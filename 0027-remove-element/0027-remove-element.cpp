class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int K = nums.size();

        for(int& N : nums)
        {
            if(N == val)
            {
                N = 1000;
                K--;
            }
        }

        sort(nums.begin() , nums.end());

        return K;
    }
};