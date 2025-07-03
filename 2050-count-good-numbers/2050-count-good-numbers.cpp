class Solution {
    const int MOD = 1e9 + 7;

    long long pow(long long x, long long exp) {
        if (exp == 0) return 1;
        long long ans = 1;
        x %= MOD;
        while (exp) {
            if (exp & 1) {
                ans = (ans * x) % MOD;
            }
            x = (x * x) % MOD;
            exp >>= 1;
        }
        return ans;
    }

public:
    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long res = (pow(5, even) * pow(4, odd)) % MOD;
        return res;
    }
};
