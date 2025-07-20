class Solution {
    vector<vector<int>> dp;

    int solve(int i, int j, string &text1, string &text2) {
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (text1[i] == text2[j]) {
            dp[i][j] = 1 + solve(i - 1, j - 1, text1, text2);
        } else {
            dp[i][j] = max(solve(i - 1, j, text1, text2), solve(i, j - 1, text1, text2));
        }

        return dp[i][j];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        dp.resize(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, text1, text2);
    }
};
