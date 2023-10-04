class MyStack {
public:
    MyStack() {
        
    }

    //실제 스택을 구현하는 것에 집착하지 말고, 스택의 특징인 FIFO를 구현하는 것에 중점을 두면 자연스럽게 구현할 수 있다
    // 따라서 마지막으로 들어온 원소를 가장 큐의 앞부분으로 보내주는 것만 구현 한다면 성공적이다
    
    void push(int x) {

        Queue1.push(x);
        int queueSize = Queue1.size();

        while(--queueSize > 0)
        {
            Queue1.push(Queue1.front());
            Queue1.pop();
        }
    }
    
    int pop() {
        int val = Queue1.front();
        Queue1.pop();
        return val;
    }
    
    int top() {
        return Queue1.front();
    }
    
    bool empty() {
        return Queue1.empty();
    }

private:
    queue<int> Queue1;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */