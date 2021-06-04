class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> countmap;

        for (auto c : s) {
            countmap[c]++;
        }

        for (int i = 0; i < s.length(); ++i) {
            if (countmap[s[i]] == 1)
                return s[i];
        }

        return ' ';
    }
};