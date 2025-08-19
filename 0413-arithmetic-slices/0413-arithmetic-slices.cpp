class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        int cnt = 0;
        int curr = 0; // number of slices ending at index i

        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                curr += 1;      // extend previous slices
                cnt += curr;    // add to answer
            } else {
                curr = 0;
            }
        }
        return cnt;
    }
};
