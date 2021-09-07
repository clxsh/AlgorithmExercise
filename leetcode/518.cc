class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int csize = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < csize; ++i) {
            int t = coins[i];
            for (int j = t; j <= amount; ++j) {
                dp[j] = dp[j] + dp[j - t];
            }
        }

        return dp[amount];
    }
};