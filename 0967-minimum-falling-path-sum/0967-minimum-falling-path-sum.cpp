class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // DP table initialized with matrix values (you can also create a new dp table)
        vector<vector<int>> dp = matrix;

        // Start filling from second-last row upwards
        for(int i = n - 2; i >= 0; --i) {
            for(int j = 0; j < m; ++j) {
                int down = dp[i + 1][j];
                int left = (j > 0) ? dp[i + 1][j - 1] : INT_MAX;
                int right = (j < m - 1) ? dp[i + 1][j + 1] : INT_MAX;

                dp[i][j] += min({down, left, right});
            }
        }

        // The answer is the minimum in the top row
        return *min_element(dp[0].begin(), dp[0].end());
    }
};
