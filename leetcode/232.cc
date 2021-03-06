class MyQueue {
private:
    stack<int> stk1;
    stack<int> stk2;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stk1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                int val = stk1.top();
                stk1.pop();
                stk2.push(val);
            }
        }
        
        int val = stk2.top();
        stk2.pop();

        return val;
    }
    
    /** Get the front element. */
    int peek() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                int val = stk1.top();
                stk1.pop();
                stk2.push(val);
            }
        }

        return stk2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty() && stk2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */