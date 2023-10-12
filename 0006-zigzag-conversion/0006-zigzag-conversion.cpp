class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        int sSize = s.size();

        if(numRows == 1) return s;

        for(int i=0; i<numRows; i++)
        {
            int index = i;
            int nextUniform = 2 * (numRows-1-i);
            while(index < sSize)
            {
                if(nextUniform) ans += s[index];
                
                index += nextUniform;

                if(nextUniform == 2 * (numRows-1-i))
                {
                    nextUniform = 2 * i;
                }else
                {
                    nextUniform = 2 * (numRows-1-i);
                }
                
            }
        }

        return ans;
    }
};