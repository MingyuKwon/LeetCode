class Solution {
public:

    unordered_map<char, string> HashMap = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"},};

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits == "") return ans;

        Recursive(ans, "", digits);
        return ans;
    }

    void Recursive(vector<string>& ans, string str, string digits)
    {
        if(digits == "")
        {
            ans.push_back(str);
            return;
        }

        for(char c : HashMap[digits[0]])
        {
            Recursive(ans, str + c, (digits.size() > 1) ? digits.substr(1, digits.size() -1) : "");
        }
    }
};