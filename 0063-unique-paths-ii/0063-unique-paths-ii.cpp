class Solution {
public:
    int solve(int i, int j, int n, int m, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        if (i == n - 1 && j == m - 1) {
            return 1;
        }

        if (i >= n || j >= m || obstacleGrid[i][j] == 1) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int down = solve(i + 1, j, n, m, obstacleGrid, dp);
        int right = solve(i, j + 1, n, m, obstacleGrid, dp);

        dp[i][j] = down + right;
        return dp[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1) {
            return 0;
        }
        
        return solve(0, 0, n, m, obstacleGrid, dp);
    }
};
