class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x != 0 && x % 10 == 0)) return false;

        long temp = x;
        long reverse = 0;
        while(temp > 0)
        {
            reverse += temp % 10;
            reverse *= 10;
            temp = temp / 10;
        }

        reverse  = reverse /10;
        if(reverse == x) return true;

        return false;
    }
};