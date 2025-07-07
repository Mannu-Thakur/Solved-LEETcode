class Solution {
    int solve(string &s, string &t, int n, int m, vector<vector<int>> &dp){
        if(n == 0 || m == 0) {
            return 0;
        }

        if(dp[n][m] != -1) {
            return dp[n][m];
        }

        if(s[n-1] == t[m-1]) {
            dp[n][m] = 1 + solve(s, t, n-1, m-1, dp);
        } else {
            dp[n][m] = max(solve(s, t, n-1, m, dp), solve(s, t, n, m-1, dp));
        }

        return dp[n][m];
    }

    string print(string &s, string &t, int n, int m, vector<vector<int>> &dp){
        string lcs = "";

        while(n > 0 && m > 0) {
            if(s[n-1] == t[m-1]) {
                lcs += s[n-1];
                n--;
                m--;
            } else if(dp[n-1][m] > dp[n][m-1]) {
                lcs += s[n-1];
                n--;
            } else {
                lcs += t[m-1];
                m--;
            }
        }

        while(n > 0) {
            lcs += s[n-1];
            n--;
        }

        while(m > 0) {
            lcs += t[m-1];
            m--;
        }

        reverse(lcs.begin(), lcs.end()); 
        return lcs;
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        int lcsLength = solve(str1, str2, n, m, dp);
        string lcs = print(str1, str2, n, m, dp);

        return lcs;
    }
};
