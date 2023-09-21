class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 1;
        int strLength = s.size();

        for(int i=1; i< strLength; i++)
        {
            if(s[i-1] == ' ' && s[i] != ' ' )
            {
                count = 1;
            }else if(s[i] != ' ')
            {
                count++;
            }
        }

        return count;
    }
};