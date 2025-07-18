class Solution {
    int solve(int n, vector<int>&nums, int ind, vector<int>&dp){
        if(ind >= n) return 0;
        if(dp[ind] != -1){
            return dp[ind];
        }

        int in = nums[ind] + solve(n, nums, ind+2, dp);
        int ex = solve(n, nums, ind+1, dp);
        return dp[ind] = max(in, ex);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int>dp(n , -1);
        return solve(n, nums, 0, dp);
    }
};