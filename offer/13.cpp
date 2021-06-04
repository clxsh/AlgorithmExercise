class Solution {
private:
    int get(int x)
    {
        int res = 0;
        for (; x; x = x / 10) {
            res += x % 10;
        }

        return res;
    }

public:
/*
    int movingCount(int m, int n, int k)
    {
        if (!k) return 1;
        queue<pair<int, int>> cubeq;
        cubeq.push(pair(0, 0));

        int count = 1;
        int dx[2] = {1, 0};
        int dy[2] = {0, 1};
        vector<vector<int>> vis(m, vector(n, 0));
        vis[0][0] = 1;
        while (!cubeq.empty()) {
            pair<int, int> t = cubeq.front();
            int x = t.first;
            int y = t.second;
            cubeq.pop();
            for (int i = 0; i < 2; ++i) {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if (tx >= m || ty >= n || vis[tx][ty] || get(tx) + get(ty) > k) continue;

                cubeq.push(pair(tx, ty));
                count++;
                vis[tx][ty] = 1;
            }
            
        }

        return count;
    }
*/
    int movingCount(int m, int n, int k)
    {
        if (!k) return 1;
        int count = 1;

        vector<vector<int>> vis(m, vector(n, 0));
        vis[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i == 0 && j == 0) || get(i) + get(j) > k) continue;

                if (i - 1 >= 0) vis[i][j] |= vis[i-1][j];
                if (j - 1 >= 0) vis[i][j] |= vis[i][j-1];

                count += vis[i][j];

                // if (i - 1 >= 0 && vis[i-1][j]) {
                //     vis[i][j] = 1;
                //     count++;
                //     continue;
                // }
                // if (j - 1 >= 0 && vis[i][j-1]) {
                //     vis[i][j] = 1;
                //     count++;
                //     continue;
                // }
            }
        }

        return count;
    }
};