class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int csize = coins.size();
        vector<uint32_t> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < csize; ++i) {
            int t = coins[i];
            for (int j = t; j <= amount; ++j) {
                dp[j] = min(dp[j], dp[j - t] + 1);
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};