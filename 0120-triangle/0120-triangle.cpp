class Solution {
    int solve(vector<vector<int>>& arr, int n, int ind, int col, vector<vector<int>>& dp) {
        if (ind == n - 1) return arr[ind][col];

        if (dp[ind][col] != -1) return dp[ind][col];

        int a = solve(arr, n, ind + 1, col, dp);
        int b = solve(arr, n, ind + 1, col + 1, dp);

        return dp[ind][col] = arr[ind][col] + min(a, b);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(triangle, n, 0, 0, dp);
    }
};
