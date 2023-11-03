class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
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
            if(i>0 && nums[i] == nums[i-1]) continue;
            
            int value = nums[i];
            nums.erase(nums.begin() + i);
            used.push_back(value);
            Recursive(result, nums,used);
            used.pop_back();
            nums.insert(nums.begin() + i, value);
        }
    }
    
    // 중복 쳐내고 경우의 수 생각해 보기
    // -> 전체 정렬한다음에 i와 i-1가 같으면 넘어가기
};