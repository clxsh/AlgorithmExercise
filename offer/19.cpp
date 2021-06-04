class Solution {
public:
/*
    bool isMatch(string s, string p) {
        if (s.length() == 0) {
            if (p.length() & 1) return false;
            for (int i = 1; i < p.length(); i += 2) {
                if (p[i] != '*') {
                    return false;
                }
            }

            return true;
        }

        if (p.length() == 0) return false;

        char a1 = s[0];
        char a2 = p[0];
        char nchar = 0;
        if (p.length() > 1) {
            nchar = p[1];
        }
        if (nchar != '*') {
            if (a1 == a2 || a2 == '.') {
                return isMatch(s.substr(1), p.substr(1));
            }
            else {
                return false;
            }
        }
        else {
            if (a1 == a2 || a2 == '.') {
                return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
            }
            else {
                return isMatch(s, p.substr(2));
            }
        }

    }
*/
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<int>> match(m + 1, vector<int>(n + 1));

        // auto comp = [&](int i, int j) {
        //     if (i == 0) return false;
        //     if (p[j - 1] == '.') return true;
        //     return s[i - 1] == p[j - 1];
        // }

        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (j == 0) {
                    match[i][j] = i == 0;
                }
                else {
                    if (p[j - 1] == '*') {
                        if (j >= 2)
                            match[i][j] |= match[i][j - 2];
                        if ((i >= 1 && j >= 2) && (s[i - 1] == p[j - 2] || p[j - 2] == '.'))
                            match[i][j] |= match[i-1][j];
                    }
                    else {
                        if (i >= 1 && (s[i - 1] == p[j - 1] || p[j - 1] == '.'))
                            match[i][j] = match[i - 1][j - 1];
                    }
                }
            }
        }

        return match[m][n];
    }
};