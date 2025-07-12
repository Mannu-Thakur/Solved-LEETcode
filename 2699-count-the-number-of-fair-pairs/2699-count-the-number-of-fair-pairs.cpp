class Solution {
public:
    // Binary search function to return the largest index i where nums[i] < target
    int bin_search(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return r;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long res = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int low = lower - nums[i];
            int up = upper - nums[i];

            int right = bin_search(nums, i + 1, n - 1, up + 1);
            int left = bin_search(nums, i + 1, n - 1, low);
            res += (right - left);
        }

        return res;
    }
};
