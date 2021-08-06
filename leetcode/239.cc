class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int nsize = nums.size();
        if (nsize == 0)
            return vector<int>{};
        
        vector<int> res;
        deque<int> descend_queue;
        int i;
        for (i = 0; i < k; ++i) {
            while (!descend_queue.empty() && descend_queue.back() < nums[i])
                descend_queue.pop_back();
            descend_queue.push_back(nums[i]);
        }
        res.push_back(descend_queue.front());
        
        for (int j = 0; i < nsize; ++i) {
            if (descend_queue.front() == nums[j])
                descend_queue.pop_front();
            ++j;

            while (!descend_queue.empty() && descend_queue.back() < nums[i])
                descend_queue.pop_back();
            descend_queue.push_back(nums[i]);
            res.push_back(descend_queue.front());
        }

        return res;
    }
};