class Solution {
private:
    vector<int> countZeroAndOne(string &s)
    {
        vector<int> count(2, 0);

        for (char c : s)
            ++count[c - '0'];

        return count;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        int ssize = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < ssize; ++i) {
            vector<int> czo = countZeroAndOne(strs[i]);
            int zero = czo[0];
            int one = czo[1];
            for (int j = m; j >= zero; --j) {
                for (int k = n; k >= one; --k) {
                    dp[j][k] = max(dp[j][k], dp[j - zero][k - one] + 1);
                }
            }
        }

        return dp[m][n];
    }
};