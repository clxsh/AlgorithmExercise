// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix)
//     {
//         int n = matrix.size();
//         if (n == 1)
//             return;

//         int rows = n / 2;
//         int cols = (n + 1) / 2;
//         for (int i = 0; i < rows; ++i) {
//             for (int j = 0; j < cols; ++j) {
//                 int t = matrix[i][j];
//                 matrix[i][j] = matrix[n - j - 1][i];
//                 matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
//                 matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
//                 matrix[j][n - i - 1] = t;
//             }
//         }

//         return;
//     }
// };

class Solution {
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        if (n == 1)
            return;

        for (int i = 0; i < n / 2; ++i) {
            swap(matrix[i], matrix[n - i - 1]);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        return;
    }
};