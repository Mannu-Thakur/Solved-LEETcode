class Solution {
    typedef long long ll;
    vector<vector<int>>dp;
    int solve(vector<int>&a, int i, int j){
        if(i+1 == j) return 0;
        ll ans = LLONG_MAX;

        if(dp[i][j] != -1) return dp[i][j];

        for(int k = i+1; k < j; ++k){
            ll temp = (a[i] * a[j] * a[k]) + solve(a, i, k) + solve(a, k, j);
             ans = min(ans, temp);
        }
        return dp[i][j] = ans;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
     dp.assign(n, vector<int>(n, -1));

       return solve(values, 0, n-1); // since first and last we already merged
    }
};