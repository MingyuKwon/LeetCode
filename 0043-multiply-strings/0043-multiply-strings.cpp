class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        if(num1 == "0" || num2 == "0") return "0";

        string result = "";
        vector<int> VECTOR(num1.size() + num2.size(), 0);

        for(int i=0; i<num1.size(); i++)
        {
            for(int j=0; j<num2.size(); j++)
            {
                int value = (num1[i] - '0') *  (num2[j] - '0');
                VECTOR[i + j] += value % 10;
                VECTOR[i + j + 1] += value / 10;
            }
        }

        for(int i=0; i<num1.size() + num2.size(); i++)
        {
            if(i<num1.size() + num2.size()-1) VECTOR[i+1] += VECTOR[i] / 10;
            VECTOR[i] = VECTOR[i] % 10;
        }

        if(VECTOR[num1.size() + num2.size()-1] == 0) VECTOR.pop_back();
        for(int num : VECTOR)
        {
            result += num + '0';
        }
        reverse(result.begin(), result.end());
        return result;
    }

    // m자리 정수 * n자리 정수를 곱하면 최종 결과는 m+n 자리 수가 나온다
    // 주로, string 자체로 다루려고 하지 않고, 다 int 벡터로 다룬다음에 최종을 string으로 만드는 방법을 채택했다

    // 모든 배열을 싹 0으로 만들어 놓고, 실시간으로 계속 더하고, upper 올려서 더하고... 계속 반복한다
    // 어찌 보면 모든 정수를 각 자리수를 의미하는 int 배열에 계속 누적해서 넣어두고, 나중에 그렇게 쌓인 숫자들을 한번에 upper로 올리는 방식이라고 할 수 있다
    // upper는 10, 100이 넘어 갈수도 있다. 그 때는 마지막 부분만 잘라서 또 올리면 될 일이다
};