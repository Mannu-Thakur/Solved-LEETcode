class Solution {
    int solve(vector<int>& cost, vector<int>& time, int n, int remain, int ind, vector<vector<int>>& dp) {
        if (remain <= 0) return 0;
        if (ind >= n) return 1e9; // Large cost for invalid case

        if (dp[ind][remain] != -1) return dp[ind][remain];

        // Option 1: Pay this painter
        int painted = cost[ind] + solve(cost, time, n, remain - 1 - time[ind], ind + 1, dp);

        // Option 2: Skip this painter
        int skipped = solve(cost, time, n, remain, ind + 1, dp);

        return dp[ind][remain] = min(painted, skipped);
    }

public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(cost, time, n, n, 0, dp);
    }
};
