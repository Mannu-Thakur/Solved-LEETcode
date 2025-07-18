class Solution {
public:
    int findLength(vector<int>& s, vector<int>& a) {
    int n = s.size(), m = a.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    int ans = 0;

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(s[i-1] == a[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}
};

 
