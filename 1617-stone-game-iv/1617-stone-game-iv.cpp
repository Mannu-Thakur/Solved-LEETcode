class Solution {
    unordered_map<int, bool> dp;

    bool solve(int n) {
        if (n == 0) return false;  
        if (dp.count(n)) return dp[n];

        for (int i = 1; i * i <= n; ++i) {
            if (!solve(n - i * i)) {
                return dp[n] = true;  
            }
        }
        return dp[n] = false;  
    }

public:
    bool winnerSquareGame(int n) {
        return solve(n);
    }
};
