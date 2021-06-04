class Solution {
public:
/*
    vector<int> printNumbers(int n) {
        vector<int> res;
        unsigned long long max_num = 0;
        for (int i = 0; i < n; ++i) {
            max_num = max_num * 10 + 9;
        }

        for (unsigned i = 1; i <= max_num; ++i) {
            res.push_back(i);
        }

        return res;
    }
*/
    vector<int> result;

    vector<int> printNumbers(int n)
    {
        string s(n, '0');
        for (int i = 0; i <= 9; ++i) {
            s[0] = '0' + i;
            permutation(s, s.length(), 1);
        }

        return result;
    }

    void permutation(string &s, int length, int pos)
    {
        if (pos == length) {
            // addtovec(s);
            int num = stoi(s);
            if (num)
                result.push_back(stoi(s));
            return;
        }
        for (int i = 0; i <= 9; ++i) {
            s[pos] = '0' + i;
            permutation(s, length, pos + 1);
        }
    }
};