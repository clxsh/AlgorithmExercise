class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int ysize = matrix[0].size();
        int xsize = matrix.size();

        int i = 0;
        int j = ysize - 1;

        while (i < xsize && j >= 0) {
            if (matrix[i][j] > target) {
                --j;
            }
            else if (matrix[i][j] < target) {
                ++i;
            }
            else {
                return true;
            }
        }

        return false;
    }
};