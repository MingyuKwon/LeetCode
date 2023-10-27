class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1) return;

        int ascendingIndex = -1;
        int descendingIndex = -1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i-1] >= nums[i])
            {
                descendingIndex = i;
            }else
            {
                ascendingIndex = i;
            }
        }

        if(ascendingIndex  == nums.size()-1) // 오름차순으로 끝나 경우
        {// 맨 뒤 2개를 바꿔주기만 하면 된다
            swap(nums[ascendingIndex], nums[ascendingIndex-1]);
        }else // 내림차순으로 끝난 경우
        {
            if(ascendingIndex == -1) 
            {
                sort(nums.begin(), nums.end());
            }else
            {
                sort(nums.begin() + ascendingIndex, nums.end());
                for(int i=ascendingIndex; i<nums.size(); i++)
                {
                    if(nums[ascendingIndex-1] < nums[i])
                    {
                        swap(nums[ascendingIndex - 1], nums[i]);
                        sort(nums.begin() + ascendingIndex, nums.end());
                        break;
                    }
                }
            }
        }

    }

    // swap은 값을 서로 교환하는 함수. 다만 vector 같은 컨테이너는 아예 컨테이너 채로 바꿔준다(내부적으로 주소값 교환 일어남)
};