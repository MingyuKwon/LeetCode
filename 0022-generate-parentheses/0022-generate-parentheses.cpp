class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        Recursive(ans, "", n, 0);
        return ans;
    }

    void Recursive(vector<string>& ans,string str, int count, int stackcount)
    {
        if(count == 0 && stackcount == 0)
        {
            ans.push_back(str);
            return;
        }

        if(stackcount == 0)// 반드시 (를 붙여야 함
        {
            Recursive(ans, str + '(', count-1, stackcount + 1);
        }else if(count == 0)
        {
            Recursive(ans, str + ')' , count, stackcount - 1);
        }else
        {
            Recursive(ans, str + '(', count-1, stackcount + 1);
            Recursive(ans, str + ')' , count, stackcount - 1);
        }

    }
};