class Solution {
public:
    string longestPalindrome(string s)
    {
        int length = s.length();

        vector<vector<bool>> dp(length, vector<bool>(length, false));
        for (int i = 0; i < length; ++i) {
            dp[i][i] = true;
        }

        int maxlen = 1;
        int start = 0;
        for (int len = 2; len <= length; ++len) {
            for (int i = 0; i < length; ++i) {
                int j = i + len - 1;

                if (j >= length)
                    break;

                if (s[i] == s[j]) {
                    if (j - i < 3)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }

                if (dp[i][j] && j - i + 1 > maxlen) {
                    maxlen = j - i + 1;
                    start = i;
                }
            }
        }

        return s.substr(start, maxlen);
    }
};