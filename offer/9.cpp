class CQueue {
private:
stack<int> stk1, stk2;

public:
    CQueue() {

    }
    
    void appendTail(int value) {
        stk1.push(value);
    }
    
    int deleteHead() {
        if (!stk2.size()) {
            int stk1_size = stk1.size();
            for (int i = 0; i < stk1_size; ++i) {
                int topush = stk1.top();
                stk1.pop();
                stk2.push(topush);
            }
        }

        if (stk2.size()) {
            int ret = stk2.top();
            stk2.pop();
            return ret;
        }

        return -1;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */