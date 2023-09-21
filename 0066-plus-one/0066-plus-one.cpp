class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int vecSize = digits.size();

        int plus = 1;

        for(int i = vecSize -1; i>= 0 && plus == 1; i--)
        {
            if(digits[i] < 9)
            {
                digits[i] += plus;
                plus = 0;
            }else
            {
                digits[i] = 0;
                if(i == 0)
                {
                    digits.insert(digits.begin(), 1);
                    plus = 0;
                }
            }
        }

        return digits;
    }
};