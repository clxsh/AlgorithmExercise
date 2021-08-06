class Solution {
private:
    vector<int> position;
    int n;
    vector<vector<string>> res;

    void recur(int k) {
        if (k == n) {
            generate();
            return;
        }

        for (int i = 0; i < n; ++i) {
            int j;
            for (j = 0; j < k; ++j) {
                if (position[j] == i || abs(k - j) == abs(i - position[j]))
                    break;
            }
            if (j == k) {
                position[k] = i;
                recur(k + 1);
            }
        }
    }

    void generate()
    {
        vector<string> vs;
        for (int i = 0; i < n; ++i) {
            string t(n, '.');
            t[position[i]] = 'Q';
            vs.emplace_back(move(t));
        }
        res.emplace_back(move(vs));
    }
public:
    vector<vector<string>> solveNQueens(int n)
    {
        this->n = n;
        position.reserve(n);
        recur(0);

        return res;
    }


};