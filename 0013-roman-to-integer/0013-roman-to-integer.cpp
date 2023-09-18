class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> MAP;

        MAP['I'] = 1;
        MAP['V'] = 5;
        MAP['X'] = 10;
        MAP['L'] = 50;
        MAP['C'] = 100;
        MAP['D'] = 500;
        MAP['M'] = 1000;

        int totalSum = 0;
        int beforeValue = 0;

        for(char ch : s)
        {
            int currentValue = MAP[ch];

            if(beforeValue < currentValue) // 앞 것이 마이너스
            {
                totalSum -= beforeValue * 2;
            }

            totalSum += currentValue;
            beforeValue = currentValue;
        }

        return totalSum;
    }
};