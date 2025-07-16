class Solution {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    void dfs(int r, int c, int n, int m, vector<vector<int>>& grid) {
        // Out of bounds or sea or already visited
        if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0) return;
        
        grid[r][c] = 0; // mark as sea to avoid visiting again
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            dfs(nr, nc, n, m, grid);
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Remove land connected to boundary
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) dfs(i, 0, n, m, grid);
            if (grid[i][m-1] == 1) dfs(i, m-1, n, m, grid);
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1) dfs(0, j, n, m, grid);
            if (grid[n-1][j] == 1) dfs(n-1, j, n, m, grid);
        }

        // Count remaining land cells
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) count++;
            }
        }

        return count;
    }
};
