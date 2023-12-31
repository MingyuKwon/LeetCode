class Solution {
public:

    int jump(vector<int>& nums) {

      for(int i = 1; i < nums.size(); i++)
      {
        nums[i] = max(nums[i] + i, nums[i-1]);
      }

      int ind = 0;
      int ans = 0;

      while(ind < nums.size() - 1)
      {
        ans++;
        ind = nums[ind];
      }

      return ans;
    }

    // 그리고 만약 어떤 시행을 했는데, 이 시행을 하는 것보다 이 시행을 하지 않는 것이 전체로 보면
    // 조건에 더 부합할 경우가 있다. 이럴 땐 이 시행을 해야 되나 하지 말아야 하는 고민이 생기는데
    // 그럴 떈, n와 n-1을 비교해서 조건에 부합하는 것을 선택하면 된다
    // n보다 1 앞의 것만 본다고 전체를 다 볼수 있냐고 할 수 있지만, 우리는 n을 0에서 전체를 다
    // 둘러 볼 것이다. 따라서 바로 앞것만 둘러봐도 전체를 다 둘러보는 효과를 가진다
    // 예를 들어 n-2 는 n이 바로 볼 수 없지만, n-1에서 이미 n-2를 보고 결과를 반영해 줬기에 n-2만 봐도
    // n-2를 자동으로 봐준 것과 동일한 효과를 가진다

    // 모든 경우의 수를 다 뒤져봐야 하는 경우에는 재귀, dp가 사용가능하다
    // 만약 속도를 더 빨리 하기 위해서는 dp를 써야 할 것이다

    // 그리고 dp는 2가지 사용방법이 있는데
    // n을 살펴 볼 때, n-1까지는 전부 이미 값이 정해져 있어서 1~n-1 값을 활용해서 n을 구하는 경우
    // n을 살펴 보고, n+1~끝까지의 값을 갱신해주는 경우. 이럴 경우 뒤에 있을 수록 갱신이 되는 
    // 횟수가 증가하게 된다

    // 주로 전자는 각 n에서 동일한 조건을 가지고 있는 경우에 사용 (i에서도 j에서도 할 수 있는 행동이 같음)
    // 후자는 각 n마다 할 수 있는 행동이 달라지는 경우에 유용하다.(i, j 에서 할 수 있는 행동이 다름)
};