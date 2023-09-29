class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> hashMap;
        string check = "";
        vector<int> Vector;

        for(char c : s)
        {
            if(hashMap.find(c) == hashMap.end())
            {
                hashMap[c] = hashMap.size();
            }

            Vector.push_back(hashMap[c]);
        }

        hashMap.clear();

        for(int i=0; i<t.size(); i++)
        {
            if(hashMap.find(t[i]) == hashMap.end())
            {
                hashMap[t[i]] = hashMap.size();
            }

            if(hashMap[t[i]] != Vector[i]) return false;

        }
        return true;
    }
};