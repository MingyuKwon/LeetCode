class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        vector<pair<int, string>> VECTOR = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        for(auto i : VECTOR)
        {
            int temp = num / i.first;
            while(temp > 0)
            {
                ans += i.second;
                temp--;
            }

            num %= i.first;
        }

        return ans;
    }
    
    
    // pair을 잘 사용하도록 하자. 기본으로 제공하는 map 경우 말고도, vector에 담을 수 있는 경우도 있다
};