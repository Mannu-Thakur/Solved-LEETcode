class Solution {
public:
    bool solve(vector<int>& nums, int index, int target, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (index == nums.size() || target < 0) return false;
        if (dp[index][target] != -1) return dp[index][target];

        // Include current element
        bool take = solve(nums, index + 1, target - nums[index], dp);
        // Exclude current element
        bool skip = solve(nums, index + 1, target, dp);

        return dp[index][target] = take || skip;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return solve(nums, 0, target, dp);
    }
};
// 