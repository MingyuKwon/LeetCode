class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int length = matrix.size();
        Recursive(matrix,length);
    }

    void Recursive(vector<vector<int>>& matrix, int size)
    {
        if(size <= 1) return;

        int length = matrix.size();
        int gap = (length - size)/2;

        size--;

        for(int i=0; i<size; i++)
        {
            int temp = matrix[gap][gap + i];

            matrix[gap][gap + i] = matrix[gap+ size - i][gap];
            matrix[gap + size - i][gap] = matrix[gap + size][gap + size - i];
            matrix[gap + size][gap + size - i] = matrix[gap + i][gap + size];
            matrix[gap + i][gap + size] = temp;
        }
        Recursive(matrix, size-1);
    }
};