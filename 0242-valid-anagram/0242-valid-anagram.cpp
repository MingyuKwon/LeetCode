class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hashMap;

        if(s.size() != t.size()) return false;

        for(char c : s)
        {
            if(hashMap.find(c) == hashMap.end())
            {
                hashMap[c] = 1;
            }else
            {
                hashMap[c]++;
            }
        }

        for(char c : t)
        {
            if(hashMap.find(c)== hashMap.end() || hashMap[c] == 0)
            {
                return false;
            }

            hashMap[c]--;
        }

        return true;
    }
};