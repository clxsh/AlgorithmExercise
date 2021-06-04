class MinStack {
private:
    stack<int> stk;
    stack<int> minstk;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        stk.push(x);
        if (minstk.empty() || x <= minstk.top())
            minstk.push(x);
    }
    
    void pop() {
        if (stk.top() == minstk.top()) {
            minstk.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int min() {
        return minstk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */