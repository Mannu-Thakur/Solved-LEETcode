class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> lastSeen(32, -1);  // last seen position of each bit

        for (int i = n - 1; i >= 0; --i) {
            // Update last seen for all bits set in nums[i]
            for (int b = 0; b < 32; ++b) {
                if (nums[i] & (1 << b)) {
                    lastSeen[b] = i;
                }
            }

            // Find farthest bit position needed
            int farthest = i;
            for (int b = 0; b < 32; ++b) {
                if (lastSeen[b] != -1) {
                    farthest = max(farthest, lastSeen[b]);
                }
            }

            res[i] = farthest - i + 1;
        }

        return res;
    }
};
