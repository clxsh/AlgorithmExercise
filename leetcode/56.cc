class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        int size = intervals.size();
        vector<vector<int>> merged;

        sort(intervals.begin(), intervals.end());
        merged.push_back(intervals[0]);

        for (int i = 1; i < size; ++i) {
            int first = intervals[i][0];
            int second = intervals[i][1];
            vector<int> &t = merged.back();
            if (t[1] < first) {
                merged.push_back(move(intervals[i]));
            }
            else {
                t[1] = max(t[1], second);
            }
        }

        return merged;
    }
};