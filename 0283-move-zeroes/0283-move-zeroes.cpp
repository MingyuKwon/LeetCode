class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                nums[j] = nums[i];
                j++;
            }
        }

        for(;j<nums.size();j++)
        {
            nums[j] = 0;
        }
    }
    //특정 조건만 만족하는 원소들만 배열에 남기기 혹은, 특정조건 만족하지 않는 원소들 뒤로 빼기라면
    //이렇게 덮어쓰기용 포인터를 하나만들어서 덮어쓰는 방식이 매우 편리하다!
};

