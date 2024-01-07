class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> resultVector = vector<vector<int>>(n, vector<int>(n,0));
        Recursive(resultVector, 0);
        return resultVector;
    }

    void Recursive(vector<vector<int>> &resultVector, int start)
    {
        // 우선 테두리를 돌 정사각형의 한 변의 길이를 구함
        int n = resultVector.size() - start * 2;
        // 정사각형의 크기가 1보다 작으면 종료
        if(n <= 0) return;

        // 시작 지점을 근거로 해서, 처음 시작할 인덱스를 구함
        int totalIndex = 1;
        if(start != 0)
        {
            totalIndex = resultVector[start][start-1] + 1;
        }

        // 시작 지점에서 n만큼 오른쪽으로 이동하면서 인덱스를 넣음
        for(int k=0; k<n; k++)
        {
            resultVector[start][start + k] = totalIndex;
            totalIndex++;
        }

        // 도착 지점에서 n-1만큼 아래로 인동하면서
        for(int k=1; k<n; k++)
        {
            resultVector[start + k][start+n-1] = totalIndex;
            totalIndex++;
        }

        // 도착 지점에서 n-1만큼 왼쪽으로 인동하면서
        for(int k=1; k<n; k++)
        {
            resultVector[start + n-1][start+n-1-k] = totalIndex;
            totalIndex++;
        }

        // 도착 지점에서 n-2만큼 위쪽으로 인동하면서
        for(int k=1; k<n-1; k++)
        {
            resultVector[start + n-1 - k][start] = totalIndex;
            totalIndex++;
        }

        Recursive(resultVector, start + 1);
    }
};