class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            while (nums[i] != i) {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }

                int tmp = nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
        }

        return 0;
    }
};