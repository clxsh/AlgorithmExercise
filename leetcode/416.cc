class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int nsize = nums.size();
        int sum = 0;
        for (int num : nums)
            sum += num;

        if (sum & 1)         // 和为奇数
            return false;

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        if (nums[0] <= target)
            dp[nums[0]] = true;

        for (int i = 1; i < nsize; ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
            
            if (dp[target] == true)
                return true;
        }

        return dp[target];
    }
};