class Solution {
public:
    string toHex(int num) {
        unsigned int NUM = num;
        string hexElement = "0123456789abcdef";

        string hex = "";
        do{
            hex += hexElement[NUM % 16];
            NUM /= 16;
        }while(NUM > 0);

        reverse(hex.begin(), hex.end());

        return hex;
    }

    //int로 표현된 -1은 비트로 표현하면 0xFFFFFFFF가 됩니다. 그리고 이걸  unsigned int로 읽게 되면 0xFFFFFFFF로 읽게 됩니다. 
    // 즉, 기존에 음수인 int 값을 unsigned int로 담게 되면 해당 int의 2의 보수값이 그대로 담기게 됩니다. 
    // -> 결국 2의 보수를 내가 처리해주지 않아도 자동으로 만들어줌
    // 이를 이용해, unsigned int로 변환한 후 16진수로 변환하는 과정에서 어떤 수가 원래 음수였는지에 대한 구분 없이 일관된 방식으로 16진수로 변환할 수 있습니다.
    // 이렇게 함으로써, 16진수로 변환하는 알고리즘을 양수와 음수에 대해 별개로 작성할 필요 없이 동일한 로직으로 처리할 수 있게 됩니다.
};