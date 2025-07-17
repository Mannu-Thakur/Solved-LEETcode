class Solution {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int dfs(int x, int y, int n, int m, vector<vector<int>>& grid) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0)
            return 0;

        grid[x][y] = 0;
        int area = 1;  // Current cell counts as area 1

        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            area += dfs(newX, newY, n, m, grid);
        }

        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(i, j, n, m, grid));
                }
            }
        }

        return maxArea;
    }
};
