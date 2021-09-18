class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stk;
        int maxans = 0;
        int slen = s.length();
        stk.push_back(-1);

        for (int i = 0; i < slen; ++i) {
            if (s[i] == '(') {
                stk.push_back(i);
            }
            else {
                stk.pop_back();
                if (stk.empty()) {
                    stk.push_back(i);  // illegal
                }
                else {
                    maxans = max(maxans, i - stk.back());
                }
            }
        }

        return maxans;
    }
};