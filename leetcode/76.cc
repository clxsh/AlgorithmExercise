class Solution {
private:
    unordered_map<char, int> origin, tmp;

    bool check()
    {
        for (const auto &ori : origin) {
            if (tmp[ori.first] < ori.second)
                return false;
        }

        return true;
    }
public:
    string minWindow(string s, string t) {
        int ssize = s.length();
        int tsize = t.length();

        for (const auto &c : t) {
            origin[c]++;
        }

        int len = INT_MAX, ansL = -1;
        int l = 0, r = -1;

        while (r < ssize) {
            if (origin.find(s[++r]) != origin.end()) {
                ++tmp[s[r]];
            }

            while (check() && l <= r) {
                int tlen = r - l + 1;
                if (tlen < len) {
                    len = tlen;
                    ansL = l;
                }

                if (origin.find(s[l]) != origin.end()) {
                    --tmp[s[l]];
                }
                ++l;
            }
        }

        return ansL == -1? "" : s.substr(ansL, len);
    }
};