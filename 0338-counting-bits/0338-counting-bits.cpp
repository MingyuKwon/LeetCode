class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> VECTOR;
        for(int i=0; i<=n; i++)
        {
            VECTOR.push_back(countBit(i));
        }

        return VECTOR;
    }

    int countBit(int n)
    {
        int count = 0;
        while(n > 0)
        {
            n = n & (n-1);
            count++;
        }
        return count;
    }
};