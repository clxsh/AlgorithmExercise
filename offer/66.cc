class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int size = a.size();
        if (!size)
            return vector<int>{};
        
        vector<int> res(size, 1);
        int left = 1, right = 1;
        for (int i = 0; i < size; ++i) {
            res[i] *= left;
            left *= a[i];

            res[size - i - 1] *= right;
            right *= a[size - i - 1];
        }

        return res;
    }
};