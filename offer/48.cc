// class Solution {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         int max_len = 0;
//         int length = s.length();
//         unordered_set<char> cset;
//         // set<char> cset;

//         int i = 0;
//         int j = 0;

//         while (i < length) {
//             if (cset.find(s[i]) == cset.end()) {
//                 cset.insert(s[i]);
//                 ++i;
//                 max_len = max(max_len, i - j);
//             }
//             else {
//                 cset.erase(s[j]);
//                 // max_len = max(max_len, i - j);
//                 ++j;
//             }
//         }

//         return max_len;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int length = s.length();
        int j = -1;
        int res = 0;
        vector<int> cmap(128, -1);

        for (int i = 0; i < length; ++i) {
            if (cmap[s[i]] != -1) {
                j = max(cmap[s[i]], j);
            }
            cmap[s[i]] = i;
            res = max(res, i - j);
        }

        return res;
    }
};