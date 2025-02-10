class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        int left = 0;
        int right = n-1;
        
        // 양 끝이 낭떠러지라는 것을 응용해 볼까?
        // 사실상 오름차순의 끝 부분을 찾으라는거랑 똑같은거 같은데
        // 내림차순의 시작도 마찬가지
        
        // 암튼 큰놈을 찾아라!


        // 큰놈 찾는게 문제가 아니라, 결국 오름차순 내림차순 문제였다
        // 현재 mid 기준으로 양옆에 있다면 그것만으로 충분

        // 판단의 기준은 mid와 mid를 활용한 지점
        // left right 모두 가능하다. left, right mid만 사용해서 풀려고 하지 말자

        while(left < right)
        {
            int mid = left + (right - left) / 2;
            
            if(nums[mid] < nums[mid+1])
            {
                left = mid + 1;
            }else
            {
                right = mid;
            }
        }
        
        return right;
    }
};