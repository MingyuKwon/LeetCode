class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";

        int aIndex = a.size() - 1;
        int bIndex = b.size() - 1;
        int plus = 0;

        while( aIndex >= 0 || bIndex >=0 || plus == 1)
        {
            if(aIndex >= 0)
            {
                plus += a[aIndex] - '0';
                aIndex--;
            }

            if(bIndex >= 0)
            {
                plus += b[bIndex] - '0';
                bIndex--;
            }

            if(plus>1)
            {
                ans += plus % 2 + '0';
                plus = 1;
            }else
            {
                ans += plus + '0';
                plus = 0;
            }
        }

        reverse(ans.begin() , ans.end());
        return ans;

    }
    
};