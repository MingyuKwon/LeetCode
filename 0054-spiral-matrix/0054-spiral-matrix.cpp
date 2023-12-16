class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        recursive(matrix, result, 0,0,matrix[0].size(), matrix.size());
        return result;
    }

    void recursive(vector<vector<int>>& matrix, vector<int>& result, int startX, int startY, int width, int height)
    {
        if(width < 1 || height < 1) return;

        for(int i= startX; i < startX + width; i++){
            if(matrix[startY][i] == 1000) continue;
            result.push_back(matrix[startY][i]);
            matrix[startY][i] = 1000;
        }

        for(int j= startY; j < startY + height; j++){
            if(matrix[j][startX + width-1] == 1000) continue;
            result.push_back(matrix[j][startX + width-1]);
            matrix[j][startX + width-1] = 1000;
        }

        for(int i= startX + width-1; i >= startX; i--){
            if(matrix[startY + height - 1][i] == 1000) continue;
            result.push_back(matrix[startY + height - 1][i]);
            matrix[startY + height - 1][i] = 1000;
        }

        for(int j= startY + height -1; j >= startY; j--){
            if(matrix[j][startX] == 1000) continue;
            result.push_back(matrix[j][startX]);
            matrix[j][startX] = 1000;
        }

        recursive(matrix, result, startX + 1, startY + 1,width-2, height-2);
    }

    //특히 2차원 배열을 반복문을 이용해서 도는 경우, 반복문 인지 i가 실제 index를 의미할 것인지 
    // 반복하는 횟수를 의미할 것인지 확실하게 정해두고 반복문을 돌아야 한다
    
    // 전자를 사용하는 경우, 반복문 안의 식은 그냥 i, j를 사용하면 되지만 반복문 조건에서 startX, startY로 보정을 해줘야 하고
    // 후자를 사용하는 경우, 반복문 안의 식에서 startX, startY로 보정을 해주고, 반복문 조건쪽에서는 그냥 사용하면 된다 
};