class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> HashMap;

        int stringCount = s.size();
        int maxCount = 0;
        int subStringCount = 0;
        
        for(int i=1; i<=stringCount; i++)
        {
            if(HashMap[s[i-1]] + subStringCount < i) // 현재 substring에 겹치는 문자가 아님 
            {
                subStringCount++;
            }else
            {
                subStringCount = i - HashMap[s[i-1]];
            }

            HashMap[s[i-1]] = i;
            maxCount = max(maxCount, subStringCount);
        }

        return maxCount;
    }
};