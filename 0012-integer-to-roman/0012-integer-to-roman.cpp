class Solution {
public:
    string intToRoman(int num) {
        int VECTOR[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        unordered_map<int, string> HashMap;
        string ans = "";

        HashMap[1000] = "M";
        HashMap[900] = "CM";
        HashMap[500] = "D";
        HashMap[400] = "CD";
        HashMap[100] = "C";
        HashMap[90] = "XC";
        HashMap[50] = "L";
        HashMap[40] = "XL";
        HashMap[10] = "X";
        HashMap[9] = "IX";
        HashMap[5] = "V";
        HashMap[4] = "IV";
        HashMap[1] = "I";

        for(int i : VECTOR)
        {
            int temp = num / i;
            while(temp > 0)
            {
                ans += HashMap[i];
                temp--;
            }

            num %= i;
        }

        return ans;
    }
};