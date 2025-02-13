
class Solution {
public:
    // k번째라는 말은 반대로 말하면 k보다 작은 놈이 k개 라는 것이고, n보다 작은 놈이 몇개인지를 세는 방식으로 풀어도 될 것 같다
    // left < right 는 right = mid에서 만약 조건을 만족하는 것이 중복해서 나열되어 있다면 그 중에서 가장 작은 놈을 가르키게 되어 있다

    // 그리고 이게 어쩌면 전혀 상관 없어 보이는 영역에서의 binary serach가 성공하게 해주는 핵심이다

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int left = 0;
        int right = nums[n-1] - nums[0];

        while(left < right)
        {
            int mid = left + (right - left) / 2;
            
            int count = countPairsWithMaxDistance(nums, mid);
            if(count < k)
            {
                left = mid + 1;
            }else
            {
                right = mid;
            }
        }

        return left;
    }

private:
    // Count number of pairs with distance <= maxDistance using a moving window
    int countPairsWithMaxDistance(vector<int>& nums, int maxDistance) {
        int count = 0;
        int n = nums.size();

        int left = 0;
        int right = 0;

        while(right < n)
        {
            while(nums[right] - nums[left] > maxDistance)
            {
                left++;
            }
            count += right - left;

            right++;
        }

        return count;
    }
};