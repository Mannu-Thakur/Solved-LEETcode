class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while (i < n) {
            int c = nums[i];
            // Check if c is in valid range (0 to n-1) and nums[i] is not at its correct index
            if (c < n && nums[i] != nums[c]) {
                swap(nums[i], nums[c]);
            } else {
                i++;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) {
                return i;
            }
        }

        return n;
    }
};
