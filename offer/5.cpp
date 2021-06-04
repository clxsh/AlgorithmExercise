class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        for (char c : s) {
            if (c == ' ')
                count++;
        }

        int len = s.size();
        s.resize(len + 2*count);

        for (int i = len - 1, j = s.size() - 1; i >= 0; --i, --j) {
            if (s[i] != ' ')
                s[j] = s[i];
            else {
                s[j]   = '0';
                s[j-1] = '2';
                s[j-2] = '%';
                j -= 2;
            }
        }

        return s;
    }
};