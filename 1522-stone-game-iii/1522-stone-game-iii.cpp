class Solution {
    int solve(vector<int>& nums, int ind, vector<int>& dp) {
        int n = nums.size();
        if(ind >= n) return 0;
        if(dp[ind] != INT_MIN) return dp[ind];

        int take = 0;
        int maxDiff = INT_MIN;

        for(int k = 0; k < 3 && ind + k < n; ++k) {
            take += nums[ind + k];
            maxDiff = max(maxDiff, take - solve(nums, ind + k + 1, dp));
        }

        return dp[ind] = maxDiff;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, INT_MIN);

        int diff = solve(stoneValue, 0, dp);

        if(diff > 0) return "Alice";
        if(diff < 0) return "Bob";
        return "Tie";
    }
};
