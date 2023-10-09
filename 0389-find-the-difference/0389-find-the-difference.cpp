class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> HashMap;

        for(char c : s)
        {
            HashMap[c]++;
        }

        for(char c : t)
        {
            HashMap[c]--;

            if(HashMap[c] < 0) return c;
        }

        return NULL;
    }
};