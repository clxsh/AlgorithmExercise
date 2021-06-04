// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         size_t maxlen = 0;
//         auto slen = s.length();
//         set<char> cset;
//         size_t i = 0;
//         size_t j = 0;
//         while (j < slen) {
//             if (cset.empty() || cset.find(s[j]) == cset.end()) {
//                 cset.insert(s[j]);
//                 ++j;
//                 maxlen = max(maxlen, j - i);
//             }else {
//                 maxlen = max(maxlen, j - i);
//                 cset.erase(s[i]);
//                 ++i;
//             }
//         }

//         return maxlen;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int t = 0;
        int j = 0;
        int res = 0;
        map<char, int> mymap;

        for (int i = 0; i < s.length(); ++i) {

            auto it = mymap.find(s[i]);
            if (it != mymap.end())
                j = it->second;
            else
                j = -1;

            mymap[s[i]] = i;
            if (t < i - j)
                t = t + 1;
            else
                t = i - j;
            res = max(res, t);
        }

        return res;
    }
};