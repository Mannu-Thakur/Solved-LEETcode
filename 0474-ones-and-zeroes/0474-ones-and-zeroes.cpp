class Solution {
    int dp[601][101][101]; // index, m, n
    
    int solve(vector<string>& strs, int i, int m, int n) {
        if (i == strs.size()) return 0;

        if (dp[i][m][n] != -1) return dp[i][m][n];

        int zero = 0, one = 0;
        for (char c : strs[i]) {
            if (c == '0') zero++;
            else one++;
        }

        // Option 1: Skip current string
        int skip = solve(strs, i + 1, m, n);

        // Option 2: Pick current string if possible
        int pick = 0;
        if (zero <= m && one <= n) {
            pick = 1 + solve(strs, i + 1, m - zero, n - one);
        }

        return dp[i][m][n] = max(pick, skip);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(strs, 0, m, n);
    }
};
