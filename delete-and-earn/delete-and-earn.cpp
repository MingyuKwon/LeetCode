class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // 그니까 value를 얻으면 그보다 1작고, 1큰놈이 싹 사라진다는 거고
        // 그렇게 얻은 최대 값을 찾으라는 건데

        // 일단 이건 배열에 담겨있는 숫자는 아예 의미가 없다
        // 인덱스에 영향을 ㅏㅇㄴ받으니까

        // 이건 그냥 다 담아두는게 좋을거 같은데

        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> dp(maxVal+1);

        for(int num : nums)
        {
            dp[num] += num;
        }

        // 4/9/4
        for(int i=2; i<=maxVal; i++)
        {
            dp[i] = max(dp[i-1], dp[i] + dp[i-2]) ;
        }

        return dp[maxVal];
    }
};