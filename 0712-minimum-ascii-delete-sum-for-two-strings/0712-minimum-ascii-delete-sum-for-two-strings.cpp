class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int word1Length = s1.size();
        int word2Length = s2.size();

        vector<vector<int>> DP = vector<vector<int>>(word1Length + 1, vector<int>(word2Length+1, 0));

        // 지워지는 것이 최소라면, 남기는 것들의 합 최대라는 것이 될 것이다
        for(int i=1; i<=word1Length; i++)
        {
            for(int j=1; j<=word2Length; j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    DP[i][j] = DP[i-1][j-1] + s1[i-1];
                }else
                {
                    DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
                }
            }
        }

        int result = 0;
        for(char c : s1)
        {
            result += c;
        }
        for(char c : s2)
        {
            result += c;
        }

        return result - 2 * DP[word1Length][word2Length];

    }
};

