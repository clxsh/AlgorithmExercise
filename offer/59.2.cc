class MaxQueue {
private:
    queue<int> queue;
    deque<int> maxq;
public:
    MaxQueue() {

    }
    
    int max_value() {
        return maxq.empty()? -1 : maxq.front();
    }
    
    void push_back(int value) {
        queue.push(value);
        while (!maxq.empty() && maxq.back() < value)
            maxq.pop_back();
        maxq.push_back(value);
    }
    
    int pop_front() {
        if (queue.empty())
            return -1;
            
        int val = queue.front();
        queue.pop();
        if (maxq.front() == val)
            maxq.pop_front();

        return val;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */