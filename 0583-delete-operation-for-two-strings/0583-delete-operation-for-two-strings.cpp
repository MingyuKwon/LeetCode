class Solution {
public:
    int minDistance(string word1, string word2) {
        // 이거야 말로 두 문자 공통 불연속 오르막 순열의 길이 최대값을 구하는 문제이다
        // 그리고 정답은 두 문자열에서을 합하고, 그 길이 *2 를 뺀 값이 답이 될것이다
        int word1Length = word1.size();
        int word2Length = word2.size();

        vector<vector<int>> DP = vector<vector<int>>(word1Length + 1, vector<int>(word2Length+1, 0));

        for(int i=1; i<=word1Length; i++)
        {
            for(int j=1; j<=word2Length; j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    DP[i][j] = DP[i-1][j-1] + 1;
                }else
                {
                    DP[i][j] = max(max(DP[i-1][j-1], DP[i-1][j]), DP[i][j-1]);
                }
                
            }
        }

        return word1Length + word2Length - DP[word1Length][word2Length]*2;


    }
};