class Solution {
public:
    int kthGrammar(int n, int k) {
        // 음 그니까 이전 거에서 0을 01로, 1을 10으로 바꾼다는거지?
        if(n == 1) return 0;

        int totalElements = pow(2, (n - 1));
        int halfElements = totalElements / 2;

        if(k > halfElements) 
        {
            return !kthGrammar(n, k - halfElements);
        }

        return kthGrammar(n-1, k);

        // 0
        // 01
        // 0110

        // 0110 1001

        // 0110 1001 1001 0110
        // 0110 1001 1001 0110 1001 0110 0110 1001


    }
};