class Solution {
public:
    int translateNum(int num) {
        string numstr = to_string(num);
        int dp[15];
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 1; i < numstr.length(); ++i) {
            if (numstr.substr(i-1, 2) <= "25" && numstr[i-1] != '0' )
                dp[i + 1] = dp[i] + dp[i - 1];
            else
                dp[i + 1] = dp[i];
        }

        return dp[numstr.length()];
    }
};