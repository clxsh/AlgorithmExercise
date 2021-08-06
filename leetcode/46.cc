class Solution {
private:
    vector<vector<int>> res;

    void recur(vector<int> &nums, int k)
    {
        int nsize = nums.size();
        if (k == nsize - 1) {
            res.emplace_back(nums);
        }

        for (int i = k; i < nsize; ++i) {
            swap(nums[i], nums[k]);
            recur(nums, k + 1);
            swap(nums[i], nums[k]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        recur(nums, 0);

        return res;
    }
};