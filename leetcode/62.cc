class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));
        dp[0][1] = 1;
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[1][j] = dp[0][j] + dp[1][j - 1];
            }
            swap(dp[0], dp[1]);
        }

        return dp[0][n];
    }
};