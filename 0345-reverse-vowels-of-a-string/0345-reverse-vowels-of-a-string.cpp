class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size()-1;

        while(left < right)
        {
            bool leftFlag = false;
            bool rightFlag = false;

            if(s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u' || 
                s[left] == 'A' || s[left] == 'E' || s[left] == 'I' || s[left] == 'O' || s[left] == 'U')
            {
                leftFlag = true;
            }else
            {
                left++;
            }   

            if(s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] == 'o' || s[right] == 'u'|| 
                s[right] == 'A' || s[right] == 'E' || s[right] == 'I' || s[right] == 'O' || s[right] == 'U')
            {
                rightFlag = true;
            }else
            {
                right--;
            }   

            if(leftFlag && rightFlag)
            {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;

                left++;
                right--;
            }


        }

        return s;
    }
};