class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> DP(nums.size()+1, 10000);
        DP[1] = 0;
        for(int i=1; i<=nums.size(); i++)
        {
            int N = nums[i-1];
            for(int k=1;i+k <= nums.size() && k<=N; k++)
            {
                DP[i+k] = min(DP[i+k], DP[i] +1);
            }
        }

        return DP[nums.size()];
    }

    // 모든 경우의 수를 다 뒤져봐야 하는 경우에는 재귀, dp가 사용가능하다
    // 만약 속도를 더 빨리 하기 위해서는 dp를 써야 할 것이다
    
    // 그리고 dp는 2가지 사용방법이 있는데
    // n을 살펴 볼 때, n-1까지는 전부 이미 값이 정해져 있어서 1~n-1 값을 활용해서 n을 구하는 경우
    // n을 살펴 보고, n+1~끝까지의 값을 갱신해주는 경우. 이럴 경우 뒤에 있을 수록 갱신이 되는 
    // 횟수가 증가하게 된다
    
    // 주로 전자는 각 n에서 동일한 조건을 가지고 있는 경우에 사용 (i에서도 j에서도 할 수 있는 행동이 같음)
    // 후자는 각 n마다 할 수 있는 행동이 달라지는 경우에 유용하다.(i, j 에서 할 수 있는 행동이 다름)
};