class Solution {
public:
    int arrangeCoins(int n) {
        if(n == 1) return 1;

        int start = 1;
        int end = n;
        long mid = start + (end - start) / 2;

        while(start <= end)
        {
            mid = start + (end - start) / 2;
            long value = mid * (mid + 1) / 2;
            if(value == n)
            {
                return mid;
            }else if(value < n)
            {
                start = mid + 1;
            }else
            {
                end = mid - 1;
            }
        }

        return end;
    }
};