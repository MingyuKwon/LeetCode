class Solution {
public:
    double myPow(double x, int n) {
        return solve(x, n);
    }

    double solve(double x, long n)
    {
        if(n < 0) return solve(1/x, -n);
        if(n == 0) return 1;

        double ans = 1;

        if(n % 2 == 1)
        {
            ans = x;
            n--;
        }

        double half = solve(x, n/2);

        return ans * half * half;

    }

    
};


