class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> direcY = {-1,0,1,0};
        vector<int> direcX = {0,-1,0,1};

        queue<pair<int,int>> bfsQueue;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 2)
                {
                    bfsQueue.push({i,j});
                }
            }
        }

        int level = 0;

        while(!bfsQueue.empty())
        {
            int count = bfsQueue.size();

            while(count--)
            {
                auto[curY, curX] = bfsQueue.front();
                bfsQueue.pop();

                for(int i=0; i<4; i++)
                {
                    int nextY = curY + direcY[i];
                    int nextX = curX + direcX[i];

                    if(nextY < 0 || nextY >= m || nextX < 0 || nextX >= n) continue;

                    if(grid[nextY][nextX] != 1) continue;

                    grid[nextY][nextX] = 2;
                    bfsQueue.push({nextY, nextX});
                }
            }

            level++;
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1) return -1;
            }
        }
        
        return level == 0 ? level : level - 1;
    }
};
