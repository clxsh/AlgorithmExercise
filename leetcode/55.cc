// (1) time limit exceeded
// class Solution {
// private:
//     bool dfs(vector<int> &nums, int size, int index)
//     {
//         if (index == size)
//             return true;

//         int t = nums[index];
//         if (t == 0)
//             return false;

//         for (int i = 1; i <= t; ++i) {
//             if (dfs(nums, size, index + i))
//                 return true;
//         }

//         return false;
//     }
// public:
//     bool canJump(vector<int>& nums) 
//     {
//         return dfs(nums, nums.size() - 1, 0);
//     }
// };

// (2) dp
// class Solution {
// public:
//     bool canJump(vector<int> &nums)
//     {
//         int nsize = nums.size();
//         vector<bool> dp(nsize, false);
//         dp[0] = true;

//         for (int i = 0; i < nsize; ++i) {
//             if (dp[i]) {
//                 int t = nums[i];
//                 for (int j = 1; j <= t; ++j) {
//                     if (i + j >= nsize) // 超界
//                         break;
//                     dp[i + j] = true;
//                 }
//             }
//             if (dp[nsize - 1])  // 找到路线直接返回
//                 break;
//         }

//         return dp[nsize - 1];
//     }
// };

class Solution {
public: 
    bool canJump(vector<int> &nums)
    {
        int k = 0;
        int nsize = nums.size();

        for (int i = 0; i < nsize; ++i) {
            if (i > k) return false;
            k = max(k, i + nums[i]);
        }

        return true;
    }
};