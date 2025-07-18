class Solution {
    int lps(string &s, string &a, int n){
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(s[i-1] == a[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
public:
    int minInsertions(string s) {
        int n  = s.length();
        string a = s;
        reverse(a.begin(), a.end());
        int ans = n-lps(s,a,n);
        return ans;
    }
};