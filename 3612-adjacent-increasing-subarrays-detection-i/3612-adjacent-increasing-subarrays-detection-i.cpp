class Solution {
    int solve(vector<int>& nums, int start, int k) {
        int n = nums.size();
        if (start + k > n) return -1;

        for (int i = start + 1; i < start + k; ++i) {
            if (nums[i] <= nums[i - 1]) return -1;
        }
        return start + k - 1;
    }

public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) return true;

        for (int i = 0; i + 2 * k <= n; ++i) {
            int end1 = solve(nums, i, k);
            if (end1 != -1) {
                int end2 = solve(nums, end1 + 1, k);
                if (end2 != -1) return true;
            }
        }
        return false;
    }
};
