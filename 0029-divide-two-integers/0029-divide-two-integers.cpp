class Solution {
public:
    int divide(int dividend, int divisor) {

        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        int isMinus = dividend < 0 ^ divisor < 0 ? -1 : 1;

        long divid = abs(dividend);
        long divis = abs(divisor);

        long sumCount = 0;

        while(divid >= divis)
        {
            long temp = divis;
            int index = 1;
            while(divid >= temp << 1)
            {
                temp = temp << 1;
                index = index << 1;
            }

            sumCount += index;
            divid -= temp;
        }

        return sumCount * isMinus; 
    }

    // 특정 수를 2진수로, 즉 2의 제곱들의 합으로 표현할 수 있는 것은 전체를 돌기에는 시간 초과가 나오는 상황에서 경우의 수를 획기적으로 줄일 수 있는 아주 좋은 방법이다
    // 전체 경우의 수가 많은 경우에, 대소비교가 가능고, 조건 만족 하는 하나의 수를 찾는다면 2의 제곱들로 만들기를 한번 시도해 보자

    // ^ 연산자는 단지 비트에서만 쓸 수 있는 게 아니라, true, false인 bool 형에도 쓰는 것이 가능

    // 곱셈은 덧셈의 연속이고, 나눗셈은 뺼셈의 연속이라고 할 수 있다

    // 그리고 INT_MAX를 음수화 한 것은  INT 범위 안이지만, INT_MIN을 양수화 한것은 INT 범위 바깥이다!

    // 이 문제는 모든 2진수로 나타낼 수 있다 -> 모든 수는 2의 거듭제곱의 합으로 나타낼 수 있다 
    // -> 조건에 맞는 수를 이진수 구하는 방법으로 구해보자. (지금까진 정해진 값을 2진수로 바꿨지만, 이젠 미지의 값을 2진수를 구해가며 찾아내고 10진수로 바꾼다)
    // 이렇게 하는 이유는 반복문을 돌면서 찾는게 이렇게 어떻게든 제곱을 살려서 찾는게 압도적으로 빠르기 때문이다
};