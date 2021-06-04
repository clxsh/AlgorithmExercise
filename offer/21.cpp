class Solution {
private:
    void swap_num(vector<int> &nums, int i, int j)
    {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
public:
    vector<int> exchange(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        if (end <= 0) return nums;

        while (start < end) {
            if (nums[start] % 2 == 0) {
                while (start < end && nums[end] % 2 == 0) --end;
                if (start < end) {
                    swap_num(nums, start, end);
                }
            }
            ++start;
        }

        return nums;
    }
};