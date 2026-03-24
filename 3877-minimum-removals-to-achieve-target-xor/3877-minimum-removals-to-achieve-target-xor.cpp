class Solution {
public:
    unordered_map<int, unordered_map<int, int>> dp; // ind and xor_val
    int n, target;

    int solve(vector<int>& nums, int ind, int currXor) {
        if (ind == n) {
            return (currXor == target) ? 0 : -1e9;
        }

        if (dp[ind].count(currXor))
            return dp[ind][currXor];

        // take
        int take = 1 + solve(nums, ind + 1, currXor ^ nums[ind]);

        // not take
        int not_take = solve(nums, ind + 1, currXor);

        return dp[ind][currXor] = max(take, not_take);
    }

    int minRemovals(vector<int>& nums, int tar) {
        n = nums.size();
        target = tar;

        int maxLen = solve(nums, 0, 0);

        if (maxLen < 0) return -1;

        return n - maxLen;
    }
};