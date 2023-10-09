class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> HashMap;

        int sSum = 0;
        int tSum = 0;

        for(char c : s)
        {
            sSum += c;
        }

        for(char c : t)
        {
            tSum += c;
        }

        return (char)(tSum - sSum);
    }
    
    // 단 하나만 차이가 나는 배열에서 그 다른 원소를 찾기 위해선
    // 그냥 배열 원소를 다 더하고, 그 값을 서로 빼서 남은 값이 하나 다른 값이 나올 것이다
};