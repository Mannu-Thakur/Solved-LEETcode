class Solution {
    int dp[501][501]; // As per constraint (<= 500)

    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if (i == 0 || j == 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (nums1[i - 1] == nums2[j - 1]) {
            return dp[i][j] = 1 + solve(nums1, nums2, i - 1, j - 1);
        } else {
            return dp[i][j] = max(solve(nums1, nums2, i - 1, j), solve(nums1, nums2, i, j - 1));
        }
    }

public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        memset(dp, -1, sizeof(dp));
        return solve(nums1, nums2, n, m);
    }
};
