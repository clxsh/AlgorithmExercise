// class Solution {
// private:
//     static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         if (matrix.size() == 0 || matrix[0].size() == 0) {
//             return {};
//         }

//         int directindex = 0;
//         int colums = matrix[0].size();
//         int rows = matrix.size();
//         int total = colums * rows;
//         vector<vector<bool>> visited(rows, vector<bool>(colums, false));
//         vector<int> result(total);
//         for (int i = 0, x = 0, y = 0; i < total; ++i) {
//             result[i] = matrix[x][y];
//             visited[x][y] = true;
//             int nextx = x + directions[directindex][0];
//             int nexty = y + directions[directindex][1];
//             if (nextx < 0 || nextx >= rows || nexty < 0 || nexty >= colums || visited[nextx][nexty]) {
//                 directindex = (directindex + 1) % 4;
//             }
//             x += directions[directindex][0];
//             y += directions[directindex][1];
//         }

//         return result;
//     }
// };

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>  &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return {};

        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;
        vector<int> res;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[top][i]);
            }
            for (int i = top + 1; i <= bottom; ++i) {
                res.push_back(matrix[i][right]);
            }
            if (left < right && top < bottom) {
                for (int i = right - 1; i > left; --i) {
                    res.push_back(matrix[bottom][i]);
                }
                for (int i = bottom; i > top; --i) {
                    res.push_back(matrix[i][left]);
                }
            }
            ++left;
            --right;
            ++top;
            --bottom;
        }

        return res;
    }
};