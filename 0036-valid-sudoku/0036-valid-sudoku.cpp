class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;

                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
        
        return true;
    }
    // 역시 중복 검사를 해도, 정해진 크기가 존재한다면 map이 아닌, 배열을 사용하는 편이 좋을 것이다
    // 그리고 중복 검사를 여러번 해야한다면, 한개를 한번쓰고 초기화 하고, 또 다시 쓰는 것 보다는
    // 유한번이라면 그냥 그 검사 개수만큼 중복 검사 배열을 만들면 된다
};