class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        long long ans = 0;

        for (int x : nums) {

            int best = x;

            // find all divisors of x
            for (int d = 1; d * d <= x; d++) {

                if (x % d == 0) {

                    // d is divisor
                    if (st.count(d)) {
                        best = min(best, d);
                    }

                    // x/d is also divisor
                    int other = x / d;

                    if (st.count(other)) {
                        best = min(best, other);
                    }
                }
            }

            ans += best;
        }

        return ans;
    }
};