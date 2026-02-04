class Solution {
    bool solve(long long mid, vector<int>& nums) {
        long long ops = 0;
        for (int f : nums) {
            ops += (f + mid - 1) / mid;
            if (ops > mid * mid) return false;
        }
        return true;
    }

public:
    int minimumK(vector<int>& nums) {
        long long low = 1;
int high = max(
    *max_element(nums.begin(), nums.end()),
    (int)nums.size()
);
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (solve(mid, nums)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
