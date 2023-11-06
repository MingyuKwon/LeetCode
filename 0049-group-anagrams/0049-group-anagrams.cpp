class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> HashMap;
        vector<string> copyStrs = strs;
        vector<vector<string>> result;

        for(string& str : copyStrs)
        {
            sort(str.begin(), str.end());
        }

        for(int i=0; i<copyStrs.size(); i++)
        {
            HashMap[copyStrs[i]].push_back(strs[i]);
        }

        for(auto a : HashMap)
        {
            result.push_back(a.second);
        }

        return result;
    }
};