class Solution {
private:
    int mergeSort(vector<int> &nums, vector<int> &tmp, int left, int right)
    {
        if (left >= right)
            return 0;
        
        int mid = (left + right) / 2;
        int inv_count = mergeSort(nums, tmp, left, mid) + mergeSort(nums, tmp, mid + 1, right);
        int i = left;
        int j = mid + 1;
        int pos = left;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                tmp[pos] = nums[i];
                ++i;
                inv_count += j - (mid + 1);
            }
            else {
                tmp[pos] = nums[j];
                ++j;
            }
            ++pos;
        }

        for (; i <= mid; ++i) {
            tmp[pos] = nums[i];
            ++pos;
            inv_count += j - (mid + 1);
        }
        for (; j <= right; ++j) {
            tmp[pos] = nums[j];
            ++pos;
        }
        copy(tmp.begin() + left, tmp.begin() + right + 1, nums.begin() + left);

        return inv_count;
    }

public:
    int reversePairs(vector<int>& nums) {
        int nsize = nums.size();
        vector<int> tmp(nsize);

        return mergeSort(nums, tmp, 0, nsize - 1);
    }
};