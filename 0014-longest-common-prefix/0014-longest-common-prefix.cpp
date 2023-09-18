class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string prefix = strs[0];
        int prefixCount = prefix.size();

        for(string str : strs)
        {
            int i=0;
            for(; i<str.size() && i < prefixCount; i++)
            {
                if(str[i] != prefix[i])
                {
                    prefixCount = i;
                    break;
                }
            }

            prefixCount = min(i,prefixCount);
        }

        if(prefixCount == 0)
        {
            return "";
        }else
        {
            return prefix.substr(0,prefixCount);
        }
        
    }
};