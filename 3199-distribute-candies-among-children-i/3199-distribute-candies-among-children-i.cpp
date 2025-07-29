class Solution {
public:
     

int dp[4][51];  

int countWays(int i, int remaining, int limit) {
    if (i == 3)
        return remaining == 0 ? 1 : 0;

    if (dp[i][remaining] != -1)
        return dp[i][remaining];

    int ways = 0;
    for (int x = 0; x <= min(remaining, limit); x++) {
        ways += countWays(i + 1, remaining - x, limit);
    }

    return dp[i][remaining] = ways;
}

int distributeCandies(int n, int limit) {
    memset(dp, -1, sizeof(dp));
    return countWays(0, n, limit);
}

};