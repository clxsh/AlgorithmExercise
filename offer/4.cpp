class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int x = matrix.size() - 1;
        int y = 0;
        while (x >= 0 && y < matrix[0].size()) {
            if (matrix[x][y] == target) {
                return true;
            }
            else if (matrix[x][y] > target) {
                --x;
            }
            else {
                ++y;
            }
        }

        return false;

    /*
        int i = matrix.size() - 1, j = 0;
        while(i >= 0 && j < matrix[0].size())
        {
            if(matrix[i][j] > target) i--;
            else if(matrix[i][j] < target) j++;
            else return true;
        }
        return false;
        */
    }
};