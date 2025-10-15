 

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int cur = 1, prev = 0;

        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                cur++;
            } else {
                // check before resetting
                if (min(prev, cur) >= k || cur / 2 >= k)
                    return true;
                prev = cur;
                cur = 1;
            }
        }

        // final check at the end
        if (min(prev, cur) >= k || cur / 2 >= k)
            return true;

        return false;
    }
};
