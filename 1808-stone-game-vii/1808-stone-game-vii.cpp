class Solution {
    vector<vector<int>> dp;
    vector<int> prefix;

    int sum(int i, int j) {
        // prefix sum for nums[i..j], inclusive
        return prefix[j + 1] - prefix[i];
    }

    int solve(vector<int>& nums, int i, int j) {
        if (i >= j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int a = sum(i + 1, j) - solve(nums, i + 1, j);
        int b = sum(i, j - 1) - solve(nums, i, j - 1);

        return dp[i][j] = max(a, b);
    }

public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));

        // Build prefix sum for O(1) range queries
        prefix.resize(n + 1);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stones[i];
        }

        return solve(stones, 0, n - 1);
    }
};
