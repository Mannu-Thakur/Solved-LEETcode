class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int freshCount = 0;
        int minutes = 0;
        

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        
        while (!q.empty() && freshCount > 0) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();
                
                for (int k = 0; k < 4; ++k) {
                    int dxx = x + dx[k];
                    int dyy = y + dy[k];
                    
                    if (dxx >= 0 && dxx < n && dyy >= 0 && dyy < m && grid[dxx][dyy] == 1) {
                        grid[dxx][dyy] = 2;
                        freshCount--;
                        q.push({dxx, dyy});
                    }
                }
            }
            minutes++;
        }
        
        return freshCount == 0 ? minutes : -1;
    }
};
