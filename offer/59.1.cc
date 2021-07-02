class Solution {
private:
    deque<int> maxVal;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty())
            return vector<int>{};

        vector<int> res;
        int i = 0;
        int j = 0;
        for (; j < k; ++j) {
            while (!maxVal.empty() && maxVal.back() < nums[j])
                maxVal.pop_back();
            maxVal.push_back(nums[j]);
        }
        res.push_back(maxVal.front());
        
        for (i++; j < nums.size(); ++i, ++j) {
            if (!maxVal.empty() && maxVal.front() == nums[i-1])
                maxVal.pop_front();
            while (!maxVal.empty() && maxVal.back() < nums[j])
                maxVal.pop_back();
            maxVal.push_back(nums[j]);
            res.push_back(maxVal.front());
        }

        return res;
    }
};