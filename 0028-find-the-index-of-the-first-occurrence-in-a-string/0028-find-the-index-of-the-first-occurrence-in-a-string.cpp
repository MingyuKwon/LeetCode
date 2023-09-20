class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystacklength = haystack.size();
        int needlelength = needle.size();

        vector<int> lps = KMPMakeLps(needle);

        for(int i=0,j=0; i < haystacklength; )
        {
            if(haystack[i] == needle[j])
            {
                i++;
                j++;
                if(j == needlelength) return i - j;
                
            }else if(j != 0)
            {
                j = lps[j-1];
            }else
            {
                i++;
            }
        }
        
        return -1;
    }

    vector<int> KMPMakeLps(string needle)
    {
        int needleLength = needle.size();
        vector<int> lps(needleLength,0);

        for(int i=1, len = 0; i<needleLength;)
        {
            if(needle[i] == needle[len])
            {
                len++;
                lps[i] = len;
                i++;
            }else if(len != 0)
            {
                len = lps[len-1];
            }else
            {
                lps[i] = 0;
                i++;
            }
        }

        return lps;
    }
};