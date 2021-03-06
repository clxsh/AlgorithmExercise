class Solution {
private:
    int left_bound(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] == target)
                right = mid - 1;
        }

        if (left >= nums.size() || nums[left] != target)
            return -1;

        return left;
    }

    int right_bound(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] == target)
                left = mid + 1;
        }

        if (right < 0 || nums[right] != target)
            return -1;
        return right;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, 0);
        res[0] = left_bound(nums, target);
        res[1] = right_bound(nums, target);

        return res;
    }
};