class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();

        // dp[i][k] = max distance reachable using first i stations and k refuels
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));
        dp[0][0] = startFuel;

        for (int i = 1; i <= n; i++) {
            long long pos = stations[i - 1][0];
            long long fuel = stations[i - 1][1];

            for (int k = 0; k <= i; k++) {
                // Case 1: don't refuel at this station
                dp[i][k] = dp[i - 1][k];

                // Case 2: take fuel from this station
                if (k > 0 && dp[i - 1][k - 1] >= pos) {
                    dp[i][k] = max(dp[i][k], dp[i - 1][k - 1] + fuel);
                }
            }
        }

        for (int k = 0; k <= n; k++) {
            if (dp[n][k] >= target)
                return k;
        }

        return -1;
    }
};
