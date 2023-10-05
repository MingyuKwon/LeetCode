class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hashMap;

        if(s.size() != t.size()) return false;

        for(char c : s)
        {
            hashMap[c]++;
        }

        for(char c : t)
        {
            hashMap[c]--;
        }

        for(auto c : hashMap)
        {
            if(c.second<0) return false;
        }

        return true;
    }
};

// 만약 hashMap에 해당 key가 없는데 데이터를 사용하려고 하면 초기값으로 배정되고 생성된다
// ++의 경우도 key가 없으면 0으로 초기화 된 후에 ++를 해주기에 key가 없다고 해서 대입이 아닌 연산이
// 오류가 나는 것은 아니다

// 그리고 돌다가 hashMap에 있는지 없는지 find로 찾는 것 보다, 그냥 value를 int로 두고, value값이 -이면 없는 것으로
// 판단하는 것이 더 빠르다