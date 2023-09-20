class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystacklength = haystack.size();
        int needlelength = needle.size();

        for(int i=0; i<=haystacklength - needlelength; i++)
        {
            if(haystack.substr(i,needlelength) == needle)
            {
                return i;
            }
        }
            
        
        return -1;
    }
};