class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!STACK1.empty())
        {
            STACK2.push(STACK1.top());
            STACK1.pop();
        }

        STACK1.push(x);

        while(!STACK2.empty())
        {
            STACK1.push(STACK2.top());
            STACK2.pop();
        }
    }
    
    int pop() {
        int val = STACK1.top();
        STACK1.pop();
        return val;
    }
    
    int peek() {
        return STACK1.top();
    }
    
    bool empty() {
        return STACK1.empty();
    }

private:
    stack<int> STACK1;
    stack<int> STACK2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */