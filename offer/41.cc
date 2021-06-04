class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> min_queue;
    priority_queue<int> max_queue;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (min_queue.size() == max_queue.size()) {
            max_queue.push(num);
            min_queue.push(max_queue.top());
            max_queue.pop();
        }
        else {
            min_queue.push(num);
            max_queue.push(min_queue.top());
            min_queue.pop();
        }

    }
    
    double findMedian() {
        if (min_queue.size() == max_queue.size()) {
            return (min_queue.top() + max_queue.top()) / 2.0;
        }
        else {
            return min_queue.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */