class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = s.length();
        if (len == 0)
            return 0;

        vector<int> cmap(128, -1);
        
        int j = -1;
        int maxlen = 0;
        for (int i = 0; i < len; ++i) {
            if (cmap[s[i]] != -1) {
                j = max(j, cmap[s[i]]);
            }
            cmap[s[i]] = i;
            maxlen = max(maxlen, i - j);
        }

        return maxlen;
    }
};