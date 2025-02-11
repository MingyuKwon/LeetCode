class Solution {
public:
    double myPow(double x, int n) {
        // 1 2 4 8 16 32 

        return solve(x, n);
    }

    double solve(double x, long long n){
        if(n == 0) return 1;
        if(n < 0) return solve(1/x, -n);

        double ans = 1;

        if(n % 2 == 1)
        {
            ans *= x;
            n--;
        }

        double half = solve(x, n/2);
        ans = ans * half * half;
        
        return ans;

    }
};


