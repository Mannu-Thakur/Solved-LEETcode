class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, 0);

        for (int i = 0; i < n; ++i) {
            int max_in_window = 0;
            for (int j = 1; j <= k && i - j + 1 >= 0; ++j) {
                max_in_window = max(max_in_window, arr[i - j + 1]);
                int sum = (i >= j ? dp[i - j] : 0) + max_in_window * j;
                dp[i] = max(dp[i], sum);
            }
        }
        return dp[n - 1];
    }
};
