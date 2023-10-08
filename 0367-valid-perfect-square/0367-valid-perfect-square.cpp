class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num;
        long mid = (left + right) / 2;
        while(left <= right)
        {
            mid = (left + right) / 2;
            long temp = mid * mid;

            if(temp == num)
            {
                return true;
            }else if(temp < num)
            {
                left = mid + 1;
            }else
            {
                right = mid - 1;
            }
        }

        return false;
    }

    // 이진탐색은 배열이 주어지는 경우 뿐만 아닌, n보다 작은 자연수 범위에서 숫자를 찾고 싶은 경우에도 사용이 가능하다.
};