class Solution {
public:
    const int MOD = 1e9 + 7;

    int dp[10001][7][7];  // n up to 1e4, values 1..6 (plus 0)

    int solve(int len, int prev1, int prev2, int n) {
        if (len == n) return 1;

        if (dp[len][prev1][prev2] != -1)
            return dp[len][prev1][prev2];

        int ans = 0;

        for (int curr = 1; curr <= 6; curr++) {

            if (prev1 != 0 && __gcd(curr, prev1) != 1) continue;
            if (curr == prev1 || curr == prev2) continue;

            ans = (ans + solve(len + 1, curr, prev1, n)) % MOD;
        }

        return dp[len][prev1][prev2] = ans;
    }

    int distinctSequences(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, n); // len, p1, p2, n
    }
};