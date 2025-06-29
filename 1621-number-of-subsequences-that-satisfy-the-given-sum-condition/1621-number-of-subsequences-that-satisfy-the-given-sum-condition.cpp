class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        const int mod = 1e9 + 7;
        vector<int> power(n, 1);  // Precompute powers of 2

        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % mod;
        }

        sort(nums.begin(), nums.end());

        int left = 0, right = n - 1;
        int count = 0;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                count = (count + power[right - left]) % mod;
                left++;
            } else {
                right--;
            }
        }

        return count;
    }
};
