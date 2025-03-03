class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // wordDict에 있는 단어들로만 s를 나눌 수 있ㄴ느지를 묻는 문제
        // 중요한 것은 wordDict에 있는 것은 전부 쓰지 않아도 되지만, s에 있는 것은 모두 써야 한다
        int n = s.size();
        vector<bool> dp(n + 1);

        dp[0] = true;

        for(int i=1; i<=n; i++)
        {
            for(string word : wordDict)
            {
                if(i < word.size()) continue;
                if(!dp[i-word.size()]) continue;

                if(s.substr(i-word.size(), word.size()) == word) 
                {
                    dp[i] = true;
                    break;
                }

                
            }
        }

        return dp[n];
    }

};