class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        dp[0] = 0;  // base case: 0 sum with 0 elements

        for (int num : nums) {
            for (int s = target; s >= num; --s) {
                if (dp[s - num] != -1) {
                    dp[s] = max(dp[s], dp[s - num] + 1);
                }
            }
        }

        return dp[target];
    }
};
