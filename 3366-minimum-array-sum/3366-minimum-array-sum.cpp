class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    int solve(int i, vector<int>& nums, int k, int op1, int op2) {
        if (i == n) return 0;

        if (dp[i][op1][op2] != -1)
            return dp[i][op1][op2];

        int x = nums[i];
        int ans = INT_MAX;

       
        ans = min(ans, x + solve(i + 1, nums, k, op1, op2));

         if (op1 > 0) {
            int val = (x + 1) / 2;
            ans = min(ans, val + solve(i + 1, nums, k, op1 - 1, op2));
        }

         if (op2 > 0 && x >= k) {
            int val = x - k;
            ans = min(ans, val + solve(i + 1, nums, k, op1, op2 - 1));
        }

 
        if (op1 > 0 && op2 > 0) {

             int val1 = (x + 1) / 2;
            if (val1 >= k) { 
                ans = min(ans, (val1 - k) + solve(i + 1, nums, k, op1 - 1, op2 - 1));
             }

              if (x >= k) {
                int val2 = x - k;
                val2 = (val2 + 1) / 2;

                ans = min(ans, val2 + solve(i + 1, nums, k, op1 - 1, op2 - 1));
            }
        }

        return dp[i][op1][op2] = ans;
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        n = nums.size();

        dp.assign( n, vector<vector<int>>( op1 + 1, vector<int>(op2 + 1, -1)));

        return solve(0, nums, k, op1, op2);
    }
};