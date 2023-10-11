class Solution {
public:
    int longestPalindrome(string s) {
        // 홀수개 -> -1해서 해서 짝수로 만들고 더함
        // 짝수개 -> 그냥 더해도 ok
        unordered_map<char, int> HashMap;
        for(char c : s)
        {
            HashMap[c]++;
        }

        int hasOdd = 0;
        int sum = 0;
        for(auto c : HashMap)
        {
            if(c.second % 2 == 0)
            {
                sum += c.second;
            }else
            {
                hasOdd = 1;
                sum += c.second - 1;
            }
        }

        return sum + hasOdd;
    }
};