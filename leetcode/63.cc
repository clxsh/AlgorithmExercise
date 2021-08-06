class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(2, vector(n + 1, 0));
        dp[0][1] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {     // 当前位置有障碍物
                    dp[1][j + 1] = 0;
                }
                else {
                    dp[1][j + 1] = dp[0][j + 1] + dp[1][j];
                }
            }
            swap(dp[0], dp[1]);
        }

        return dp[0][n];
    }
};