class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        if(nums.size() < 4) return ans;

        for(int i=0; i<nums.size()-3; i++)
        {
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<nums.size()-2; j++)
            {
                if(j>i+1 && nums[j] == nums[j-1]) continue;

                int left = j+1;
                int right = nums.size()-1;

                while(left < right)
                {
                    long sum = static_cast<long>(nums[i]) + nums[j] + nums[left] + nums[right];
                    long gap = target - sum;

                    if(gap>0)
                    {
                        left++;
                    }else if(gap<0)
                    {
                        right--;
                    }else
                    {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        int leftvalue = nums[left];
                        int rightvalue = nums[right];

                        while(left < nums.size() && leftvalue == nums[left])
                        {
                            left++;
                        }

                        while(right >= 0 && rightvalue == nums[right])
                        {
                            right--;
                        }
                    }
                }
            }
        }

        return ans;
    }

    // 정렬을 하는 이유 중 하나가, 범위를 기준으로 구분할 수가 있어져서 이다
    // 정렬 해 놓고 최소와 최대를 잡아 놓는 경우, 나머지 점들은 반드시 최소와 최대 사이에 존재한다
    // 이 점을 이용해서 집합 영역을 나눌 수 있다  

    // 근데 그래도 4개를 n2이나 n2longn으로 바꾸는 것은 무리이다 
};