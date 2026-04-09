class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;

        for (int i = 2; i <= sqrt(n); ++i) {
            while (n % i == 0) {
                if (i != 2 && i != 3 && i != 5) {
                    return false;
                }
                n /= i;
            }
        }

        // 🔴 leftover prime factor
        if (n > 1 && n != 2 && n != 3 && n != 5) {
            return false;
        }

        return true;
    }
};