class Solution {
public:
    int findLucky(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Count frequencies
        for (int num : nums) {
            freq[num]++;
        }

        int ans = -1;
        // Check for lucky numbers
        for (auto &p : freq) {
            if (p.first == p.second) {
                ans = max(ans, p.first);
            }
        }

        return ans;
    }
};
