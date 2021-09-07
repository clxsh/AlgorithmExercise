class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (obstacleGrid[i][j - 1] != 1)
                    dp[j] = dp[j - 1] + dp[j];
                else
                    dp[j] = 0;
            }
        }

        return dp[n];
    }
};