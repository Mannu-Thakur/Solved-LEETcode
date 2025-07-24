class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL), sum = 0;
        int n = nums.size(), partial = n, complete = n * (target / total), start = 0;
        target %= total;
        for (int end = 0; end < 2 * n; end++) {
            sum += nums[end % n];
            while (sum > target) {
                sum -= nums[start++ % n];
            }
            if (sum == target) {
                partial = min(partial, end - start + 1);
            }
        }
        return partial != n ? partial + complete : -1;
    }
};