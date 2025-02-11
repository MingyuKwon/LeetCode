class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num;

        while(left <= right)
        {
            long long mid = left + (right - left)/2;
            long long powValue = mid * mid;

            if(powValue == num) return true;

            if(powValue < num)
            {
                left = mid + 1;
            }else
            {
                right = mid - 1;
            }
        }

        return false;
    }

};