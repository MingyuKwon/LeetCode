class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        queue<pair<int,int>> bfsQueue;
        
        vector<vector<bool>> seen(n, vector<bool>(n, false));
        bfsQueue.push({0,0});
        seen[0][0] = true;
    
        vector<int> dirX = {0,0,1,1,1,-1,-1,-1};
        vector<int> dirY = {-1,1,0,-1,1,0,-1,1};

        int level = 1;

        while(!bfsQueue.empty())
        {
            int count = bfsQueue.size();

            while(count--)
            {
                auto[currentY, currentX] = bfsQueue.front();
                bfsQueue.pop();

                if(currentY == n-1 && currentX == n-1) return level;

                for(int i=0; i<8; i++)
                {
                    int nextY = currentY + dirY[i];
                    int nextX = currentX + dirX[i];

                    if(nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) continue;

                    if(grid[nextY][nextX] == 0 && !seen[nextY][nextX]) 
                    {
                        seen[nextY][nextX] = true;
                        bfsQueue.push({nextY, nextX});
                    }
                }
            }

            level++;
        }

        return -1;
    }
};
