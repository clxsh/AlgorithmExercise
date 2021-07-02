class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string sub = s.substr(0, n);

        copy(s.begin() + n, s.end(), s.begin());
        copy(sub.begin(), sub.end(), s.end() - n);

        return s;
    }
};