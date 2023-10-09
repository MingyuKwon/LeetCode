class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(t.size() < s.size()) return false;

        int sIndex = 0;
        int tIndex = 0;

        while(sIndex < s.size() && tIndex < t.size())
        {
            if(s[sIndex] == t[tIndex])
            {
                sIndex++;
            }
            tIndex++;
        }

        return sIndex == s.size();

    }
};