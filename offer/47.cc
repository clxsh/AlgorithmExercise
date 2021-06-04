class Solution {
private:
    int dp[202][202];
public:
    int maxValue(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == 0 && j == 0) {
                    dp[0][0] = grid[0][0];
                }
                else if (i == 0) {
                    dp[0][j] = dp[0][j - 1] + grid[0][j];
                }
                else if (j == 0) {
                    dp[i][0] = dp[i - 1][0] + grid[i][0];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }

        return dp[rows - 1][cols - 1];
    }
};