class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int patternSize = pattern.size();
        unordered_map<char, int> HashMap1;
        unordered_map<string, int> HashMap2;

        istringstream in(s);
        string word;
        int index = 0;

        while(in >> word)
        {
            if(HashMap1[pattern[index]] != HashMap2[word] || index == patternSize) return false;

            HashMap1[pattern[index]] = index + 1;
            HashMap2[word] = index + 1;
            index++;
        }

        return index == patternSize;
    }

    // 일단 두 선형 탐색의 패턴이 동일한지 아닌지를 판단하려면 hashMap을 사용하는 것이 좋다
    // 그리고 서로 비교하면서 동일한지 아닌지를 확인하고, 동일하지 않다면 false를 반환하도록 한다
    // 어짜피 둘다 앞에서 뒤로 훑으면서 이미 지난 값은 다시 사용안하므로 hashMap의 값을 계속 변환시켜도 이후에만 정상작동하면 문제 없다
    // 그리고 둘이 길이가 다른 경우에는 그냥 틀린 것이므로 false를 반환해야한다
    // 그리고 절대 hashMap의 value로 0을 넣지 마라. 새로운 초기값이 0으로 되는데, 기존 0이랑 헷갈려서 오류를 낼 수도 있다

    // 그리고 문자열을 화이트 스페이스 기준으로 자르고 싶다면 istringstream을 이용해서 하나하나 입력을 받아서 각 token을 받아서 이용하도록 하자
    // 유사 split  느낌을 줄것이다
};


