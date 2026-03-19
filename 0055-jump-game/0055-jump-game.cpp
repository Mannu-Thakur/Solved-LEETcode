class Solution {
public:
    bool solve(vector<int>& nums, int i, vector<int>& dp) {
        int n = nums.size();
        if(i >= n - 1) return true;

        if(dp[i] != -1) return dp[i];

        for(int jump = 1; jump <= nums[i]; ++jump){
            if(solve(nums, i + jump, dp))
                return dp[i] = 1;
        }
        return dp[i] = 0;
    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};