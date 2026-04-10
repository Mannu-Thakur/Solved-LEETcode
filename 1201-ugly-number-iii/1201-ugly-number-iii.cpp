class Solution {
public:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    long long count(long long x, long long a, long long b, long long c) {
        long long ab = lcm(a, b);
        long long bc = lcm(b, c);
        long long ac = lcm(a, c);
        long long abc = lcm(a, bc);

        return (x / a) + (x / b) + (x / c)
             - (x / ab) - (x / bc) - (x / ac)
             + (x / abc);
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long left = 1, right = 2e9;

        while (left < right) {
            long long mid = left + (right - left) / 2;

            if (count(mid, a, b, c) >= n)
                right = mid;
            else
                left = mid + 1;
        }

        return (int)left;
    }
};