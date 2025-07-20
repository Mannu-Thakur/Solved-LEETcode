
class Solution {
  public:
    int solve(vector<int>& coins, int sum, int n, vector<vector<int>>& dp, int ind) {
        if (sum == 0) return 0;
        
        if (sum < 0 || ind == n) return INT_MAX;
        
        if (dp[ind][sum] != -1) return dp[ind][sum];
        
        int include = INT_MAX, exclude = INT_MAX;
        
        if (sum >= coins[ind]) {
            int result = solve(coins, sum - coins[ind], n, dp, ind);
            if (result != INT_MAX) {
                include = result + 1;  
            }
        }
        
        exclude = solve(coins, sum, n, dp, ind + 1);
        
        dp[ind][sum] = min(include, exclude);
        
        return dp[ind][sum];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        
        int result = solve(coins, amount, n, dp, 0);
        
        return result == INT_MAX ? -1 : result;
    }
};

