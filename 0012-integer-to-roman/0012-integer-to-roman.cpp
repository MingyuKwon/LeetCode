class Solution {
public:
    string intToRoman(int num) {
        vector<int> VECTOR;
        unordered_map<int, string> HashMap;
        string ans = "";

        VECTOR.push_back(1000);
        VECTOR.push_back(900);
        VECTOR.push_back(500);
        VECTOR.push_back(400);
        VECTOR.push_back(100);
        VECTOR.push_back(90);
        VECTOR.push_back(50);
        VECTOR.push_back(40);
        VECTOR.push_back(10);
        VECTOR.push_back(9);
        VECTOR.push_back(5);
        VECTOR.push_back(4);
        VECTOR.push_back(1);

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