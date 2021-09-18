class Solution {
private:
    void recur(string &t, int lBracket, int rBracket, vector<string> &res)
    {
        if (lBracket == 0 && rBracket == 0) {
            res.push_back(t);
        }

        if (lBracket != 0) {
            t.push_back('(');
            recur(t, lBracket - 1, rBracket + 1, res);
            t.pop_back();
        }

        if (rBracket != 0) {
            t.push_back(')');
            recur(t, lBracket, rBracket - 1, res);
            t.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string t;
        vector<string> res;
        recur(t, n, 0, res);

        return res;
    }
};