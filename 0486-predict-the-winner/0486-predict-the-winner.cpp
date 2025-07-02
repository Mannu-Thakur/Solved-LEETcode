class Solution {
    int solve(vector<int>&nums, int i, int j, vector<vector<int>>&dp){
        if( i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int left = nums[i]  - solve(nums, i+1, j, dp);
        int right = nums[j] - solve(nums, i, j-1, dp);
        return dp[i][j] = max(left, right);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 ) return true;
        vector<vector<int>>dp(n, vector<int>(n, -1));
        if(solve(nums, 0 , n-1, dp) >= 0) return true; // positive ans = alice winner
        return false;
    }
};