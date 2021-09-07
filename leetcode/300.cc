class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int nsize = nums.size();
        vector<int> sublen(nsize, 1);
        int maxlen = 1;

        for (int i = 1; i < nsize; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    sublen[i] = max(sublen[i], sublen[j] + 1);
                }
            }
            maxlen = max(sublen[i], maxlen);
        }

        return maxlen;
    }
};