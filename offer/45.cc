class Solution {
private:
    void quicksort(vector<string> &strs, int left, int right)
    {
        if (left >= right)
            return;
            
        int i = left;
        int j = right;
        while (i < j) {
            while (strs[j] + strs[left] >= strs[left] + strs[j] && i < j)
                j--;
            while (strs[i] + strs[left] <= strs[left] + strs[i] & i < j)
                i++;
            swap(strs[i], strs[j]);
        }
        swap(strs[left], strs[i]);
        quicksort(strs, left, i - 1);
        quicksort(strs, i + 1, right);
    }
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for (int i = 0; i < nums.size(); ++i) {
            strs.push_back(to_string(nums[i]));
        }

        quicksort(strs, 0, strs.size() - 1);

        string res;
        for (int i = 0; i < strs.size(); ++i)
            res.append(strs[i]);

        return res;
    }
};