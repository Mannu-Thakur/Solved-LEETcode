class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(), sat.end());
        int n = sat.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = n-1; i >= 0; i--){
            for(int t = n-1; t >= 0; t--){
                dp[i][t] = max(
                    sat[i]*(t+1) + dp[i+1][t+1],
                    dp[i+1][t]
                );
            }
        }

        return dp[0][0];
    }
};
