class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size(), idx_range = (n - 2); // [1...n-2]
        long long ans = 0;

        if (idx_range & 1) { // [1,2,3,4,5]
            for (int i = 1; i <= n - 2; i += 2) {
                int mx = max(nums[i - 1], nums[i + 1]); // 7, 10, 8
                if (nums[i] <= mx) ans += (mx + 1 - nums[i]);
            }
        }
        else {
            // i, i+1
            // [1,2,3,4,5,6,7,8]
            long long op1 = 0, op2 = 0;

            for (int i = 1; i <= n - 3; i += 2) {
                int mx = max(nums[i - 1], nums[i + 1]);
                if (nums[i] <= mx) op1 += (mx + 1 - nums[i]);
            }

            for (int i = 2; i <= n - 2; i += 2) {
                int mx = max(nums[i - 1], nums[i + 1]);
                if (nums[i] <= mx) op2 += (mx + 1 - nums[i]);
            }

            ans = min(op1, op2);

            vector<long long> pre(n), suff(n); // pre[i] = min operations required to make [1...i] as special

            for (int i = 1; i <= n - 2; i += 2) {
                int op = 0, mx = max(nums[i - 1], nums[i + 1]);
                if (nums[i] <= mx) op = (mx + 1 - nums[i]);
                pre[i] = op + (i - 2 >= 0 ? pre[i - 2] : 0);
            }

            for (int i = n - 2; i >= 1; i -= 2) {
                int op = 0, mx = max(nums[i - 1], nums[i + 1]);
                if (nums[i] <= mx) op = (mx + 1 - nums[i]);
                suff[i] = op + (i + 2 < n ? suff[i + 2] : 0);
            }

            for (int i = 2; i <= n - 4; i++) {
                int left = i - 1, right = n - i - 3;
                if (left & 1 && right & 1)
                    ans = min(ans, pre[i - 1] + suff[i + 2]);
            }
        }

        return ans;
    }
};