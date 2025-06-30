class Solution {
public:
    int dp[501][501];

    int helper(vector<int>& piles, int i, int j) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        // Choose left pile
        int pickLeft = piles[i] - helper(piles, i + 1, j);
        // Choose right pile
        int pickRight = piles[j] - helper(piles, i, j - 1);

        // Store and return the best outcome
        return dp[i][j] = max(pickLeft, pickRight);
    }

    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return helper(piles, 0, piles.size() - 1) > 0;
    }
};
