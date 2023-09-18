class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x != 0 && x % 10 == 0)) return false;

        // 굳이 전체를 다 뒤집지 않아도, 절반만 뒤집어도 문제 없다. 오히려 절반만 뒤집는게, 아직 안 뒤집힌 부분하고, 뒤집힌 부분ㄴ하고 비교하면 바로 대칭여부를 알 수 있다
        int reverse = 0;
        while(x > reverse)
        {
            reverse *= 10;
            reverse += x % 10;
            
            x = x / 10;
        }

        return (reverse == x || reverse / 10 == x );
    }
};