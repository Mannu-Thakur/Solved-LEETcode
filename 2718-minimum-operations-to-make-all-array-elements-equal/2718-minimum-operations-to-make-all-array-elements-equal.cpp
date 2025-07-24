class Solution {
    typedef long long ll;
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<ll> prefix(n + 1, 0); // prefix sum of nums

        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        vector<ll> res;
        for (int q : queries) {
            int idx = lower_bound(nums.begin(), nums.end(), q) - nums.begin();

            // nums[0 ... idx-1] < q
            // nums[idx ... n-1] >= q

            ll left = (ll)q * idx - prefix[idx];
            ll right = (prefix[n] - prefix[idx]) - (ll)q * (n - idx);
            res.push_back(left + right);
        }
        return res;
    }
};
