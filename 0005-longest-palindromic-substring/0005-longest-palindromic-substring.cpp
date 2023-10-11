class Solution {
public:
    string longestPalindrome(string s) {
        int strSize = s.size();
        int maxSize = 1;
        int maxLeft = 0;
        int maxRight = 0;

        for(int i=0; i < strSize; i++)
        {
            int left = i-1;
            int right = i+1;
            int count = 1;

            while(left>=0 && right<strSize)
            {
                if(s[left] != s[right]) break;

                count += 2;
                left--;
                right++;
            }

            if(maxSize < count)
            {
                maxSize = count;
                maxLeft = left+1;
                maxRight = right-1;
            }

            count = 0;
            left = i-1;
            right = i;

            while(left>=0 && right<strSize)
            {
                if(s[left] != s[right]) break;

                count += 2;
                left--;
                right++;
            }

            if(maxSize < count)
            {
                maxSize = count;
                maxLeft = left+1;
                maxRight = right-1;
            }

        }

        return s.substr(maxLeft,maxRight - maxLeft+1);
    }
    // 그리고 기본적으로 문자열 n의 substring의 개수는 n^2개 이므로 모든 substring을 본다는 가정하에 반드시 n^2가 필수이다
    // 그리고 n 차원 dp는 시간복잡도가 n1 * n2 * ... n3 개가 기본으로 걸린다. 만약 n2 , n3 등이 유한한 경우라면 기간복잡도가 한단계 내려가지만 그렇지 않으면 저대로
    // 꼭, dp의 값이 우리가 원하는 값일 필요는 없다. 그냥 값은  true, false로 두고 이를 이용 할 수도 있을 것이다
};