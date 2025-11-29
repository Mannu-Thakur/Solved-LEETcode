class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n + 1, 0);

        
        for (int i = 1; i <= n; ++i)
            pref[i] = pref[i - 1] + nums[i - 1];

         vector<long long> best(k, LLONG_MAX);
        best[0] = 0;   
        long long ans = LLONG_MIN;

        for (int r = 1; r <= n; ++r) {
            int mod = r % k;

            if (best[mod] != LLONG_MAX) {
                long long cand = pref[r] - best[mod];
                ans = max(ans, cand);
            }

            best[mod] = min(best[mod], pref[r]);
        }

        return ans;
    }
};
