class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int nsize = nums.size();
        int left = 0;
        int right = nsize - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == mid) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        // return nums[left] == left ? right : left;
        // return left == nums.size() - 1 ? nums.size() : left;

        return nums[nsize - 1] == nsize - 1 ? nsize : left;
    }
};