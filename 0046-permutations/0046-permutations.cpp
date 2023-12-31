class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        Recursive(result, nums, {});
        return result;
    }

    void Recursive(vector<vector<int>>& result, vector<int>& nums, vector<int> used)
    {
        if(nums.size() == 0) 
        {
            result.push_back(used);
            return;
        }

        for(int i=0; i<nums.size(); i++)
        {
            int value = nums[i];
            nums.erase(nums.begin() + i);
            used.push_back(value);
            Recursive(result, nums,used);
            used.pop_back();
            nums.insert(nums.begin() + i, value);
        }
    }
};