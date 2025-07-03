class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        long long exp = n;  // Convert to long long to handle INT_MIN case
        if (exp < 0) {
            x = 1.0 / x;
            exp = -exp;
        }
        double ans = 1.0;
        while (exp) {
            if (exp & 1) { // when bit is set
                ans *= x;
            }
            x *= x; 
            exp >>= 1;
        }
        return ans;
    }
};


// using binary exponentiation
