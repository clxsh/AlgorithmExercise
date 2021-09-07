// #include <iostream>
// #include <vector>
// #include <memory>
// #include <algorithm>
// using namespace std;

// struct point {
//     int x;
//     int y;
//     int val;

//     point(int _x = 0, int _y = 0, int _val = 0)
//         : x(_x), y(_y), val(_val) {}
// };

// bool comp(const shared_ptr<point> &p1, const shared_ptr<point> &p2)
// {
//     return p1->val < p2->val;
// }

// class Solution {
// public:
//     int longestIncreasingPath(vector<vector<int>>& matrix)
//     {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         int total = m * n;

//         int longest = 1;
//         vector<vector<int>> dp(m, vector<int>(n, 1));

//         vector<shared_ptr<point>> msort(total);
//         int index = 0;
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 msort[index] = make_shared<point>(i, j, matrix[i][j]);
//                 ++index;
//             }
//         }
//         sort(msort.begin(), msort.end(), comp);

//         for (int i = 0; i < total; ++i) {
//             int x = msort[i]->x;
//             int y = msort[i]->y;
//             int val = msort[i]->val;
//             if (x > 0 && matrix[x - 1][y] < val) {
//                 dp[x][y] = max(dp[x][y], dp[x - 1][y] + 1);
//             }
//             if (x + 1 < m && matrix[x + 1][y] < val) {
//                 dp[x][y] = max(dp[x][y], dp[x + 1][y] + 1);
//             }
//             if (y > 0 && matrix[x][y - 1] < val) {
//                 dp[x][y] = max(dp[x][y], dp[x][y - 1] + 1);
//             }
//             if (y + 1 < n && matrix[x][y + 1] < val) {
//                 dp[x][y] = max(dp[x][y], dp[x][y + 1] + 1);
//             }

//             longest = max(longest, dp[x][y]);
//         }

//         return longest;
//     }
// };

// int main()
// {
//     int m, n;
//     cin >> m >> n;
//     vector<vector<int>> matrix(m, vector<int>(n));

//     for (int i = 0; i < m; ++i) {
//         for (int j = 0; j < n; ++j) {
//             cin >> matrix[i][j];
//         }
//     }

//     Solution solu;
//     solu.longestIncreasingPath(matrix);

//     return 0;
// }

// 记忆深搜
class Solution {
private:
    int gm;
    int gn;
    static constexpr int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &memo, int x, int y)
    {
        if (memo[x][y] != 0)
            return memo[x][y];
        
        int t = 1;
        for (int i = 0; i < 4; ++i) {
            int dx = x + dirs[i][0];
            int dy = y + dirs[i][1];
            if (dx >= 0 && dx <gm && dy >= 0 && dy < gn && matrix[dx][dy] > matrix[x][y]) {
                t = max(t, dfs(matrix, memo, dx, dy) + 1);
            }
        }
        memo[x][y] = t;

        return t;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        gm = matrix.size();
        gn = matrix[0].size();

        vector<vector<int>> memo(gm, vector<int>(gn, 0));
        int ans = 1;
        for (int i = 0; i < gm; ++i) {
            for (int j = 0; j < gn; ++j) {
                ans = max(ans, dfs(matrix, memo, i, j));
            }
        }

        return ans;
    }
};