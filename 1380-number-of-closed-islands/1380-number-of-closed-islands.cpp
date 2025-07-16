class Solution {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(int r, int c, int n, int m, vector<vector<int>>& grid) {
        if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 1) return;
        grid[r][c] = 1; // mark as visited (flip to water)
        for (int i = 0; i < 4; i++) {
            dfs(r + dx[i], c + dy[i], n, m, grid);
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // Step 1: Flood-fill boundary-connected land to water
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0) dfs(i, 0, n, m, grid);
            if (grid[i][m-1] == 0) dfs(i, m-1, n, m, grid);
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 0) dfs(0, j, n, m, grid);
            if (grid[n-1][j] == 0) dfs(n-1, j, n, m, grid);
        }

        // Step 2: Count closed islands inside the grid
        int count = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    dfs(i, j, n, m, grid);
                }
            }
        }

        return count;
    }
};
