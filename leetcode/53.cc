class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int nsize = nums.size();
        
        int subsum = nums[0];
        int maxsum = subsum;

        for (int i = 1; i < nsize; ++i) {
            if (subsum < 0)
                subsum = nums[i];
            else
                subsum += nums[i];

            maxsum = max(maxsum, subsum);
        }

        return maxsum;
    }
};