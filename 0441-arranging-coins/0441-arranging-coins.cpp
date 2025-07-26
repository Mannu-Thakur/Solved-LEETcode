class Solution {
public:
    int arrangeCoins(int n) {
        int left = 0;
        int right = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long val = 1LL * mid * (mid + 1) / 2;

            if (val == n) {
                return mid;
            } else if (val < n) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right; // or left - 1 depending on final requirement
    }
};
