class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());   
        vector<vector<int>> ans;

        for(int i=0; i<nums.size()-2; i++)
        {
            if(nums[i] > 0) break;
            if(i>0 && nums[i-1] == nums[i]) continue;

            int left = i + 1;
            int right = nums.size()-1;

            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum < 0)
                {
                    left++;
                }else if(sum > 0)
                {
                    right--;
                }else
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    int leftValue = nums[left];
                    int rightValue = nums[right];

                    while(left < nums.size() && leftValue == nums[left])
                    {
                        left++;
                    }

                    while(right >=0 && nums[right] == rightValue)
                    {
                        right--;
                    }
                }
            }
        }

        return ans;    
    }


    // 이 문제는 이진 탐색으로 접근하는 것이 아니라, 전체를 다 봐야 하는 것이다
    // 하지만 그냥 썡으로 전체를 다 보면 반드시 nC3 으로 시간 복잡도 n3를 가지게 된다
    // 거기에서 정렬을 쓴다면, 시간 복잡도를 한칸 내릴 수 있는 방법이 존재한다. 

    // 크기 비교가 필요한 경우, 의미가 있는데 정렬이 되어 있으면 숫자보다 큰지 아닌지를 알아서 배제 하는 것이 가능해진다
    // 이문제를 풀 수 없었던 패착은, 정렬 해서 시간 복잡도를 낮추는 것 까지는 잘 생각했지만 시간 복잡도를 logN으로 낮추는 것에만 집중을 했다.
    // 따라서 n의 복잡도로 두수의 합의 경우의수를 찾아보는 방법을 생각을 못했었다.

    // 그리고 중복 피하는 방법은 한번 답을 구하고 나면, 중복 중에서 가장 오른쪽/ 왼쪽으로 옮겨서 중복을 없앴다
};