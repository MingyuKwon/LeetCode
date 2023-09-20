class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystacklength = haystack.size();
        int needlelength = needle.size();

        for(int i=0; i<=haystacklength - needlelength; i++)
        {
            int j=0;

            for(; j< needlelength; j++)
            {
               if(haystack[i+j] != needle[j]) 
               {
                   break;
               }
            }

            if(j == needlelength)
            {
                return i;
            }
        }
            
        
        return -1;
    }
};