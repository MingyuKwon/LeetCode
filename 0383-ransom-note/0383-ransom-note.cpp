class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        if(ransomNote.size() > magazine.size()) return false;

        unordered_map<char, int> HashMap;

        for(char c : magazine)
        {
            HashMap[c]++;
        }

        for(char c : ransomNote)
        {
            HashMap[c]--;
            if(HashMap[c] < 0) return false;
        }

        return true;


    }
};