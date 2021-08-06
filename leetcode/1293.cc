struct position {
    int x, y;
    int rest;
    position(int _x = 0, int _y = 0, int _rest = 0)
        : x(_x), y(_y), rest(_rest) {}
};

class Solution {
private:
    static constexpr int dirs[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

public:
    int shortestPath(vector<vector<int>>& grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 1 && n == 1)
            return 0;
        
        if (k > m + n - 3)
            return m + n - 2;

        bool visited[m][n][k + 1];
        memset(visited, false, sizeof(visited));
        visited[0][0][k] = true;
        queue<position> q;
        q.emplace(0, 0, k);


        for (int step = 1; q.size() > 0; ++step) {
            int qsz = q.size();
            for (int t = 0; t < qsz; ++t) {
                position pos = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int dx = pos.x + dirs[i][0];
                    int dy = pos.y + dirs[i][1];
                    if (dx >= 0 && dx < m && dy >= 0 && dy < n) {
                        if (grid[dx][dy] == 0 && !visited[dx][dy][pos.rest]) {
                            if (dx == m - 1 && dy == n - 1)
                                return step;
                            q.emplace(dx, dy, pos.rest);
                            visited[dx][dy][pos.rest] = true;
                        }
                        else if (grid[dx][dy] == 1 && pos.rest > 0 && !visited[dx][dy][pos.rest - 1]) {
                            q.emplace(dx, dy, pos.rest - 1);
                            visited[dx][dy][pos.rest - 1] = true;
                        }
                    }
                }
            }
        }

        return -1;
    }
};