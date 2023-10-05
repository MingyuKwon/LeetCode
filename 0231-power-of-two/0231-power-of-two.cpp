class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n <= 0) return false;

        return (n & n-1) == 0;
    }
};

// 2의 제곱수 -> 2진수로 나타내면 첫번쨰가 1이고 나머지 뒤 부분은 0이어야 함
// 그러면 n-1 은 첫자리 0이고 나머지는 전부 1이어야함
// 결국 n-1 & n을 하면 0밖에 남지 않아야 함
// 그게 아니라면 2의 제곱수가 아니다 