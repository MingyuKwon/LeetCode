class Solution {
public:
    bool isPowerOfThree(int n) {

        if(n <= 0) return false;

        return (int)pow(3,floor(log(INT_MAX)/log(3))) % n == 0;
    }

    // 핵심은 n의 k차승의 숫자는 오로지 n의 l(l<=k)차승의 숫자로만 깔끔하게 나눠진다
    // 이 말을 반대로 하면, 범위내의 가장 큰 n의 제곱 수를 검사해 볼 숫자로 나눴을 때 깔끔하게 안나눠 떨어지면 그건  n의 제곱수가 아니라는 결론이 된다  
};