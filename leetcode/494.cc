// class Solution {
// private:
//     int count;

//     void trackBack(vector<int> &nums, int target, int k, int sum)
//     {
//         int nsize = nums.size();
//         if (k == nsize) {
//             if (sum == target)
//                 ++count;
//             return;
//         }

//         trackBack(nums, target, k + 1, sum + nums[k]);
//         trackBack(nums, target, k + 1, sum - nums[k]);            
//     }
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         count = 0;
//         trackBack(nums, target, 0, 0);

//         return count;    
//     }
// };

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int nsize = nums.size();
        int sum = 0;
        for (int i = 0; i < nsize; ++i)
            sum += nums[i];
        
        int t = sum - target;
        if (t < 0 || t & 1)
            return 0;

        t = t >> 1;
        vector<int> dp(t + 1, 0);
        // if (nums[0] < t + 1)          //跳过第一个，跳过了一层。。
        //     dp[nums[0]] = 1;
        dp[0] = 1;

        for (int i = 0; i < nsize; ++i) {
            for (int j = t; j >= nums[i]; --j) {
                if (j - nums[i] >= 0)
                    dp[j] += dp[j - nums[i]];
            }
        }

        return dp[t];
    }
};