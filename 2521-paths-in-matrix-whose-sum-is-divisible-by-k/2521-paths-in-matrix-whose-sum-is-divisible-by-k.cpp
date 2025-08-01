#include <bits/stdc++.h>
using namespace std;

class Solution {
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& grid, int k, int n, int m, int i, int j, int sum) {
        if (i == n - 1 && j == m - 1) {
            return ((sum + grid[i][j]) % k == 0) ? 1 : 0;
        }

        if (dp[i][j][sum] != -1) return dp[i][j][sum];

        long long ways = 0;

        // Move Down
        if (i + 1 < n) {
            ways += solve(grid, k, n, m, i + 1, j, (sum + grid[i][j]) % k);
        }
        // Move Right
        if (j + 1 < m) {
            ways += solve(grid, k, n, m, i, j + 1, (sum + grid[i][j]) % k);
        }

        return dp[i][j][sum] = ways % mod;
    }

public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        // ✅ allocate dp properly
        dp.assign(n, vector<vector<int>>(m, vector<int>(k, -1)));

        return solve(grid, k, n, m, 0, 0, 0);
    }
};
