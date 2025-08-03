class Solution {
    int dx[4] = {-1, 1, 0, 0};  
    int dy[4] = {0, 0, -1, 1};
public:
    int solve(int n, int m, vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {
        if (i >= n || j >= m) {
            return 0; 
        }

        if (dp[i][j] != -1) { 
            return dp[i][j];
        }

        int len = 1;  
        for (int k = 0; k < 4; k++) {
            int newX = i + dx[k];
            int newY = j + dy[k];

            if (newX >= 0 && newY >= 0 && newX < n && newY < m && matrix[newX][newY] > matrix[i][j]) {
                len = max(len, 1 + solve(n, m, matrix, newX, newY, dp)); 
            }
        }

        dp[i][j] = len; 
        return len;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));  

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, solve(n, m, matrix, i, j, dp));
            }
        }

        return ans;
    }
};