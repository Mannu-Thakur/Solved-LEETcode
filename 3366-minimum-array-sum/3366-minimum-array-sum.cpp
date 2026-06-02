class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();

        const int INF = 1e9;

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(op1 + 1,
            vector<int>(op2 + 1, INF))
        );

        dp[0][0][0] = 0;

        for (int i = 0; i < n; i++) {

            for (int a = 0; a <= op1; a++) {

                for (int b = 0; b <= op2; b++) {

                    if (dp[i][a][b] == INF) continue;

                    int x = nums[i];

                    // 1. Do nothing
                    dp[i + 1][a][b] =
                        min(dp[i + 1][a][b],
                            dp[i][a][b] + x);

                    // 2. Only op1
                    if (a < op1) {
                        int y = (x + 1) / 2;

                        dp[i + 1][a + 1][b] =
                            min(dp[i + 1][a + 1][b],
                                dp[i][a][b] + y);
                    }

                    // 3. Only op2
                    if (b < op2 && x >= k) {
                        int y = x - k;

                        dp[i + 1][a][b + 1] =
                            min(dp[i + 1][a][b + 1],
                                dp[i][a][b] + y);
                    }

                    // 4. Both operations
                    if (a < op1 && b < op2) {

                        int best = INF;

                        // op1 -> op2
                        int y1 = (x + 1) / 2;

                        if (y1 >= k) {
                            best = min(best, y1 - k);
                        }

                        // op2 -> op1
                        if (x >= k) {
                            int y2 = (x - k + 1) / 2;
                            best = min(best, y2);
                        }

                        if (best != INF) {
                            dp[i + 1][a + 1][b + 1] =
                                min(dp[i + 1][a + 1][b + 1],
                                    dp[i][a][b] + best);
                        }
                    }
                }
            }
        }

        int ans = INF;

        for (int a = 0; a <= op1; a++) {
            for (int b = 0; b <= op2; b++) {
                ans = min(ans, dp[n][a][b]);
            }
        }

        return ans;
    }
};