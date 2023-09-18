class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string prefix = strs[0];
        int cutIndex = prefix.size() - 1;

        for(string str : strs)
        {
            int i=0;
            for(; i<str.size() && i <= cutIndex; i++)
            {
                if(str[i] != prefix[i])
                {
                    cutIndex = i-1;
                    break;
                }
            }

            cutIndex = min(i-1,cutIndex);
        }

        if(cutIndex < 0)
        {
            return "";
        }else
        {
            return prefix.substr(0,cutIndex+1);
        }
        
    }
};