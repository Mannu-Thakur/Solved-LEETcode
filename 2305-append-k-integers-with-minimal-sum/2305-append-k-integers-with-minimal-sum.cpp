class Solution {
    typedef long long ll;
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        ll ans = 0, prev = 0;
        for (int x : nums) {
            ll L = prev + 1;
            ll R = x - 1;

            if (L <= R) {
                ll cnt = min((ll)k, R - L + 1);
                ll end = L + cnt - 1;
                ans += (L + end) * cnt / 2;
                k -= cnt;
            }
            if (k == 0) return ans;
            prev = x;
        }

        if (k > 0) {
            ll L = prev + 1;
            ll R = L + k - 1;
            ans += (L + R) * k / 2;
        }

        return ans;
    }
};
