class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = n;

        int i = 0;
        for (int j = 0; j < n; ++j) {
            while (nums[j] > 1L * nums[i] * k) { // use 1L to avoid overflow
                i++;
            }
            ans = min(ans, n - (j - i + 1));
        }

        return ans;
    }
};
