class Solution {
    int f(int ind, int pre_ind, vector<int>& nums, int n, vector<vector<int>>& dp) {
         if (ind == n) return 0;

         if (dp[ind][pre_ind + 1] != -1) return dp[ind][pre_ind + 1];

         int len = f(ind + 1, pre_ind, nums, n, dp);

         if (pre_ind == -1 || nums[ind] > nums[pre_ind]) {
            len = max(len, 1 + f(ind + 1, ind, nums, n, dp));
        }

         return dp[ind][pre_ind + 1] = len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
         vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, nums, n, dp);
    }
};
