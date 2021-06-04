class Solution {
private:
    vector<string> res;
    void dfs(string s, int x)
    {
        if (x == s.length() - 1) {
            res.push_back(s);
        }

        set<char> st;
        for (int i = x; i < s.length(); ++i) {
            if (st.find(s[i]) != st.end())
                continue;
            st.insert(s[i]);
            swap(s[x], s[i]);
            dfs(s, x + 1);
            swap(s[x], s[i]);
        }
    }
public:
    vector<string> permutation(string s) {
        dfs(s, 0);

        return res;
    }
};