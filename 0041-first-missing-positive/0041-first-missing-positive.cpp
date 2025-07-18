class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            if (nums[i] > 0 && nums[i] <= n) { // ✅ Ensure nums[i] is valid before using it
                int c = nums[i] - 1;
                if (nums[i] != nums[c]) {
                    swap(nums[i], nums[c]);
                } else {
                    i++;
                }
            } else {
                i++;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
