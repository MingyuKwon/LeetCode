class Solution {
public:
    bool isHappy(int n) {
        int fast = n;
        int slow = n;

        while(powEachNum(fast) != 1)
        {
            slow = powEachNum(slow);
            fast = powEachNum(powEachNum(fast));

            if(fast == slow) return false;
        }

        return true;
    }

    int powEachNum(int n)
    {
        int sum = 0;
        while(n)
        {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }

        return sum;
    }
};

