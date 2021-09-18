static constexpr char keyboard[11][5] = {{}, {}, {'a', 'b', 'c'},
                                                        {'d', 'e', 'f'},
                                                        {'g', 'h', 'i'},
                                                        {'j', 'k', 'l'},
                                                        {'m', 'n', 'o'},
                                                        {'p', 'q', 'r', 's'},
                                                        {'t', 'u', 'v'},
                                                        {'w', 'x', 'y', 'z'}};

class Solution {
private:
    int glen;    
    void recur(string &digits, char *t, int k, vector<string> &res)
    {
        if (k == glen) {
            t[k] = 0;
            res.emplace_back(t);
            return;
        }

        int d = static_cast<int>(digits[k] - '0');
        const char *tkeyboard = static_cast<const char *>(keyboard[d]);
        int csize = strlen(tkeyboard);
        for (int i = 0; i < csize; ++i) {
            t[k] = tkeyboard[i];
            recur(digits, t, k + 1, res);
        }
    }
public:
    vector<string> letterCombinations(string &digits)
    {
        glen = digits.length();
        if (glen == 0)
            return vector<string>{};

        vector<string> res;
        char tmp[5];

        recur(digits, tmp, 0, res);

        return res;
    }
};