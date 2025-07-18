class Solution {
    int solve(string &s, string &t, int n, int m, vector<vector<int>>&dp){
        if(n == 0 ) return m;
        if(m == 0 ) return n;

        if(dp[n][m] != -1){
            return dp[n][m];
        } 

        if(s[n-1] == t[m-1]){
            dp[n][m] = solve(s, t, n-1, m-1, dp);
        } else {
            int del1 = solve(s, t, n, m-1, dp);
            int del2 = solve(s, t, n-1, m, dp);
            dp[n][m] = 1 + min(del1, del2);
        }

        return dp[n][m];
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1 , -1));
        return solve(word1, word2, n, m, dp);
    }
};
