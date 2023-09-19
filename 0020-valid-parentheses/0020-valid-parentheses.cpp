class Solution {
public:
    bool isValid(string s) {
        stack<char> STACK;
        for (char ch : s)
        {
            if(ch == '(' || ch == '{' || ch == '[')
            {
                STACK.push(ch);
            }else
            {
                if(STACK.size() < 1) return false;

                if(ch == ')' && STACK.top() == '(')
                {
                    STACK.pop();
                }else if(ch == '}'  && STACK.top() == '{')
                {
                    STACK.pop();
                }else if(ch == ']'  && STACK.top() == '[')
                {
                    STACK.pop();
                }else
                {
                    return false;
                }
            }
        }

        if(STACK.size() > 0) return false;

        return true;
    }
};