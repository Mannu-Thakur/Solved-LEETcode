class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 0) return 0;
        if (n == 1) return cost[0];

        // dp[i] will be the minimum cost to reach the ith step
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; ++i) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        // Minimum cost to reach the top can be from either the last step or the second last step
        return min(dp[n-1], dp[n-2]);
    }
};
