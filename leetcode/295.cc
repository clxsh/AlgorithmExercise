class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;
    int size;
public:
    /** initialize your data structure here. */
    MedianFinder() : size(0) {}
    
    void addNum(int num)
    {
        if (size & 1) {  // 奇数个
            min_heap.push(num);
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        else {
            max_heap.push(num);
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        ++size;
    }
    
    double findMedian()
    {
        if (size & 1)
            return min_heap.top();
        else
            return (min_heap.top() + max_heap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */