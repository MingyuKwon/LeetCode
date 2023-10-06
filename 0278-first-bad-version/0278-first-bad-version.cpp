// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long left = 1;
        long right = n;
        long middle = (left + right) / 2;

        while(left <= right)
        {
            middle = (left + right) / 2;
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

};