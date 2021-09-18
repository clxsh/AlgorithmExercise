class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        int ssize = strs.size();
        map<string, vector<string>> mp;

        for (int i = 0; i < ssize; ++i) {
            string s = strs[i];
            sort(begin(s), end(s));
            mp[s].emplace_back(move(strs[i]));
        }

        vector<vector<string>> res;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            res.emplace_back(move(it->second));
        }

        return res;
    }
};