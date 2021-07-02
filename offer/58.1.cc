class Solution {
public:
    string reverseWords(string s) {
        string tmp = "";
        s += ' ';
        vector<string> res;

        for (auto ch : s) {
            if (ch != ' ') {
                tmp += ch;
            }
            else {
                if (!tmp.empty())
                    res.emplace_back(move(tmp));
            }
        }

        string ret = "";
        vector<string>::reverse_iterator riter = res.rbegin();
        for (; riter != res.rend(); ++riter) {
            ret += *riter;
            ret += " ";
        }
        ret.pop_back();

        return ret;
    }
};