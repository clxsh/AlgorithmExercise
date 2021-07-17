class Solution {
private:
    int rows;
    int cols;
    bool isExist(vector<vector<char>> &board, string &word, int a, int b, int k)
    {
        if (a >= rows || a < 0 || b >= cols || b < 0 || board[a][b] != word[k])
            return false;
        if (k == word.length() - 1)
            return true;

        board[a][b] = 0;
        bool res = (isExist(board, word, a + 1, b, k + 1) || isExist(board, word, a, b + 1, k + 1)
                 || isExist(board, word, a - 1, b, k + 1) || isExist(board, word, a, b - 1, k + 1));
        board[a][b] = word[k];

        return res;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (isExist(board, word, i, j, 0))
                    return true;
            }
        }
        
        return false;
    }
};