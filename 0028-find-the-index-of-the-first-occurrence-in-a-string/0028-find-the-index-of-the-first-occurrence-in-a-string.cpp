class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int index = -1;
        int i=0;
        
        if(haystack.size() < needle.size())
        {
            return -1;
        }else
        {
            
        
        for(; i<=haystack.size() - needle.size(); i++)
        {
            index = i;

            int j=0;

            for(; j< needle.size(); j++)
            {
               if(haystack[i+j] != needle[j]) 
               {
                   break;
               }
            }

            if(j == needle.size())
            {
                break;
            }
        }
            
        }


        if(i > haystack.size() - needle.size()) return -1;

        return index;
    }
};