class Solution {
    int solve(int n, vector<int>&nums1, vector<int>&nums2, int i, int j, vector<vector<int>>&dp){
        if(i == n){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int res = INT_MAX;

        for(int k = 0; k < n; ++k){
            if(!(j & ( 1 << k))){
                res = min(res, (nums1[i] ^ nums2[k] ) + solve(n, nums1, nums2, i+1, j | ( 1 << k), dp));
            } 
        }
        return dp[i][j] = res;
    }
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>>dp(n, vector<int>( 1 << n, -1));
        return solve(n, nums1, nums2, 0, 0, dp);
        
    }
};