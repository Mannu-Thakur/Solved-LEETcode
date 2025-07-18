class Solution {
   int dp[2512];
    
    
    int stair(int i) {
        if (i == 0) return 1; 
        if (i == 1) return 1;  
        
        if (dp[i] != -1) return dp[i];

        dp[i] = stair(i-1) + stair(i-2);
        
        return dp[i];
    }

public:
    int climbStairs(int n) {
    memset(dp,-1,sizeof(dp));
        return stair(n);  
    }
};
