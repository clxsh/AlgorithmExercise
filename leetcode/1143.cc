class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int len1 = text1.length();
        int len2 = text2.length();

        vector<vector<int>> maxlen(len1 + 1, vector<int>(len2 + 1, 0));

        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    maxlen[i][j] = maxlen[i - 1][j - 1] + 1;
                }
                else {
                    maxlen[i][j] = max(maxlen[i - 1][j], maxlen[i][j - 1]);
                }
            }
        }

        return maxlen[len1][len2];
    }
};