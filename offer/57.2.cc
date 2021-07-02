class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        vector<int> tmp;

        for (int left = 1, right = 2; left < right;) {
            int sum = (left + right) * (right - left + 1) / 2 ;
            if (sum < target) {
                right++;
            }
            else if (sum > target) {
                left++;
            }
            else {
                tmp.clear();
                for (int i = left; i <= right; ++i) {
                    tmp.emplace_back(i);
                }
                res.emplace_back(tmp);
                left++;
            }
        }

        return res;
    }
};