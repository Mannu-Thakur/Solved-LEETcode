class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long total = 0;
        for (auto x : nums) total = (total + x) % p;
        if (total == 0) return 0;

        unordered_map<int, int> last_occurrence;
        last_occurrence[0] = -1;
        long long prefix = 0;
        int ans = n;

        for (int i = 0; i < n; ++i) {
            prefix = (prefix + nums[i]) % p;
            int need = (prefix - total + p) % p;
            if (last_occurrence.count(need)) {
                ans = min(ans, i - last_occurrence[need]);
            }
            last_occurrence[prefix] = i;
        }

        return ans == n ? -1 : ans;
    }
};
