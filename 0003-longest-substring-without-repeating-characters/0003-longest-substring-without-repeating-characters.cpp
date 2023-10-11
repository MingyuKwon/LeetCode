class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> HashMap;

        int stringCount = s.size();
        int maxCount = 0;
        int subStringCount = 0;
        
        for(int i=0; i<stringCount; i++)
        {
            if(!HashMap.count(s[i]) || subStringCount + HashMap[s[i]] < i) // 현재 substring에 겹치는 문자가 아님 
            {
                subStringCount++;
            }else
            {
                subStringCount = i - HashMap[s[i]];
            }

            HashMap[s[i]] = i;
            maxCount = max(maxCount, subStringCount);
        }

        return maxCount;
    }

    // count를 이용해서 map을 뒤지는 것이 가능, find 쓰지 말자
};