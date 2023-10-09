class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> HashMap;

        for(char i : s)
        {
            HashMap[i]++;
        }

        for(int i=0; i<s.size(); i++)
        {
            if(HashMap[s[i]] == 1) return i;
        }

        return -1;
    }
};