class Solution {
private:
    int left_bound(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        cout << "left: " << left << endl;
        cout << "right:" << right << endl;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            cout << "mid: " << mid << endl;
            if (nums[mid] == target)
                right = mid - 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
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
            if (nums[mid] == target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
        }

        if (right < 0 || nums[right] != target)
            return -1;
        
        return right;
    }
public:
    int search(vector<int>& nums, int target)
    {
        if (nums.empty())
            return 0;
        
        int left = left_bound(nums, target);
        int right = right_bound(nums, target);

        if (left == -1)
            return 0;

        return right - left + 1;
    }
};
