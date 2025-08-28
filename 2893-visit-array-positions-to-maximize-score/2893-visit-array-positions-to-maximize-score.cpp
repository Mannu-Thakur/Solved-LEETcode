class Solution {
    typedef long long ll;

public:
    long long maxScore(vector<int>& nums, int x) {
        ll dp_even = -1e18, dp_odd = -1e18;  
        if (nums[0] % 2 == 0) dp_even = nums[0];
        else dp_odd = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                // nums[i] is even
                dp_even = max(dp_even + nums[i], dp_odd + nums[i] - x);
            } else {
                // nums[i] is odd
                dp_odd = max(dp_odd + nums[i], dp_even + nums[i] - x);
            }
        }

        return max(dp_even, dp_odd);
    }
};
