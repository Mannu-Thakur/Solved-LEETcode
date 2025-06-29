class Solution {
    int solve(string &word1, string &word2, int i, int j, vector<vector<int>>& dp) {
        if (i == 0) return j;
        if (j == 0) return i;
        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i - 1] == word2[j - 1]) {
            dp[i][j] = solve(word1, word2, i - 1, j - 1, dp);
        } else {
            int insertOp = solve(word1, word2, i - 1, j, dp);
            int deleteOp = solve(word1, word2, i, j - 1, dp);
            int replaceOp = solve(word1, word2, i - 1, j - 1, dp);
            dp[i][j] = 1 + min(insertOp, min(deleteOp, replaceOp));
        }
        return dp[i][j];
    }

public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(word1, word2, n, m, dp);
    }
};
