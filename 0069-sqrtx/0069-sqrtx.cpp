class Solution {
public:
    int mySqrt(int x) {
        int min = 0;
        int max = x;
        int mid = 0;

        while(min <= max)
        {
            mid = (min + max) / 2;
            long result = (long)mid * mid;
            if(x == result)
            {
                return mid;
            }else if( x > result)
            {
                min = mid +1;
            }else
            {
                max = mid -1;
            }
        }

        return max;

        return 0;
    }
};