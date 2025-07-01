class Solution {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool solve(int n, int m, int i, int j, int fromx, int fromy,
               vector<vector<char>>& grid, vector<vector<bool>>& vis, char target) {
        vis[i][j] = true;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = i + dx[dir];
            int ny = j + dy[dir];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == target) {
                if (!vis[nx][ny]) {
                    if (solve(n, m, nx, ny, i, j, grid, vis, target)) {
                        return true;
                    }
                } else if (nx != fromx || ny != fromy) {
                    return true; // Cycle detected
                }
            }
        }

        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j]) {
                    if (solve(n, m, i, j, -1, -1, grid, vis, grid[i][j])) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
