class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        string str = countAndSay(n-1);
        
        int count = 1;
        string result = "";
        for(int i=1; i<str.size(); i++)
        {
            if(str[i-1] == str[i])
            {
                count++;
            }else
            {
                result += ('0' + count);
                result += str[i-1];        
                count = 1;
            }
        }

        result += ('0' + count);
        result += str[str.size()-1];

        return result;
    }
};