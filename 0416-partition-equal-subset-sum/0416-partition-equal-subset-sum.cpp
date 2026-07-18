class Solution {
     bool solve(vector<int>& arr, int n, int sum, int ind,
               vector<vector<int>>& dp) {

        if(sum == 0)
            return true;

        if(ind == n || sum < 0)
            return false;

        if(dp[sum][ind] != -1)
            return dp[sum][ind];

        bool take = solve(arr, n, sum - arr[ind], ind + 1, dp);
        bool notTake = solve(arr, n, sum, ind + 1, dp);

        return dp[sum][ind] = take || notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        auto sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum % 2 != 0) return false;

        int target = sum/2;

        vector<vector<int>> dp(target + 1, vector<int>(n + 1, -1));

        return solve(nums, n, target, 0, dp);



    }
};