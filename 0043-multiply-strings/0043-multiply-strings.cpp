class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        if(num1 == "0" || num2 == "0") return "0";

        string result = "";

        vector<string> VECTOR;

        for(int i=0; i<num1.size(); i++)
        {
            int upper = 0;
            string temp = "";
            for(int j=0; j<num2.size(); j++)
            {
                int value = (num1[i] - '0') *  (num2[j] - '0') + upper;
                temp += (value % 10) + '0';
                upper = value / 10;
            }

            if(upper > 0) temp += upper + '0';
            VECTOR.push_back(temp);
        }

        int index = 0;
        for(string str : VECTOR)
        {
            if(index == 0)
            {
                result += str;
            }else
            {
                if(result.size() - 1 < index)
                {
                    result += str;
                }else
                {
                    int j = 0;
                    int upper = 0;

                    while(j < str.size() || upper > 0)
                    {
                        if(index + j >= result.size())
                        {
                            if(j >= str.size())
                            {
                                result += upper + '0';
                                upper = 0;
                            }else
                            {
                                int value = (str[j] - '0') + upper;
                                result += (value % 10) + '0';
                                upper = value/10;
                            }
                        }else
                        {
                            if(j >= str.size())
                            {
                                int value = (result[index + j] - '0') + upper;
                                result += (value % 10) + '0';
                                upper = value/10;
                            }else
                            {
                                int value = (result[index + j] - '0') + (str[j] - '0') + upper;
                                result[index + j] = (value % 10) + '0';
                                upper = value/10;
                            }

                        }

                        j++;
                    }
                    
                }
                
            }

            index++;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};