// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int middle = left + (right - left)/2;

        while(left <= right)
        {
            middle = left + (right - left)/2;
            if(isBadVersion(middle))
            {
                right = middle-1;
            }else
            {
                left = middle + 1;
            }
        }


        return left;
    }
// 여기서 중요한 것은 이진 탐색을 할 때 mid를 구하는 것이 (left + right) /2 가 아니라
// mid = left + (right - left) / 2로 하는 것이다
// 후자는 게산 결과 전자와 동일하게 되지만,
// 전자는 left+ right에서 overflow가 일어날 수도 있지만 후자는 그럴 일이 없다

};

