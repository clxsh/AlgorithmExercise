class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int nsize = nums.size();
        if (nsize < 2)
            return;

        int i = nsize - 2;
        int j = nsize - 1;

        while (i >= 0 && nums[i] >= nums[j]) {
            --i;
            --j;
        }
        if (i < 0) {  // 纯降序
            reverse(begin(nums), end(nums));
            return;
        }

        int k = nsize - 1;
        while (k >= j) {
            if (nums[i] < nums[k])
                break;
            --k;
        }
        
        swap(nums[i], nums[k]);
        reverse(nums.begin() + j, nums.end());

        return;
    }
};