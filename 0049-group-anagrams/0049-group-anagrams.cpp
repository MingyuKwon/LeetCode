class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> HashMap;
        vector<vector<string>> result;

        int i = 0;
        for(string str : strs)
        {
            sort(str.begin(), str.end());
            HashMap[str].push_back(strs[i]);
            i++;
        }

        for(auto a : HashMap)
        {
            result.push_back(a.second);
        }

        return result;
    }

    // 결국 아나그램을 부수는 것에는 정렬이 답인것 같다. 
    // 아나그램해서 동일한 것은 정렬하면 모두 동일하게 나온다
};