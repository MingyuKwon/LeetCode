class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ansVecs(numRows);

        for(int i=0; i < numRows; i++)
        {
            for(int j = 0; j< i + 1; j++)
            {
                ansVecs[i].push_back(1);
            }
            
            for(int j=1; j < i ; j++)
            {
                ansVecs[i][j] =  ansVecs[i-1][j-1] + ansVecs[i-1][j];
            }
        }   

        return ansVecs;

    }
};