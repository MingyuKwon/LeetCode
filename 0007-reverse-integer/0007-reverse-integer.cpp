class Solution {
public:
    int reverse(int x) {
        int isMinus = 1;
        if(x < 0) isMinus = -1;

        x = abs(x);
        long result = 0;

        while(x > 0)
        {
            result *= 10;
            result += x % 10;
            x /= 10;
            if(result < INT_MIN || result > INT_MAX) return 0;
        }

        return static_cast<int>(result) * isMinus;
    }
};