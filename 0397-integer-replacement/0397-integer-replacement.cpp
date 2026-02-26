class Solution {
public:
    int integerReplacement(int n) {
        return solve((long long)n);
    }

private:
    int solve(long long n) {
        if (n == 1) return 0;

        if (!(n & 1))   // even
            return 1 + solve(n >> 1);  // divide by 2
        else
            return 1 + min(solve(n - 1), solve(n + 1));
    }
};