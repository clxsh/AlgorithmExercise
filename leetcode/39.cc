class Solution {
private:
    void dfs(vector<int> &candidates, int begin, int size, vector<int> &path, vector<vector<int>> &res, int target)
    {
        if (target == 0)
            res.emplace_back(path);

        for (int i = begin; i < size; ++i) {
            int t = candidates[i];
            if (target < t)
                continue;
            path.push_back(t);
            dfs(candidates, i, size, path, res, target - t);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        int csize = candidates.size();
        vector<vector<int>> res;
        vector<int> tmp;

        dfs(candidates, 0, csize, tmp, res, target);

        return res;
    }
};