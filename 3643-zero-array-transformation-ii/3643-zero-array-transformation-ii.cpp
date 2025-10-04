class Solution {
public:
    // helper: check if first k queries can zero nums
    bool canZero(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<long long> diff(n + 1, 0);

        // apply first k queries using difference array
        for (int i = 0; i < k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            diff[l] += val;
            if (r + 1 < n) diff[r + 1] -= val;
        }

        long long allowance = 0;
        for (int i = 0; i < n; i++) {
            allowance += diff[i];
            if (allowance < nums[i]) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size();
        int left = 0, right = m, ans = -1;

         while (left <= right) {
            int mid = (left + right) / 2;
            if (canZero(nums, queries, mid)) {
                ans = mid;
                right = mid - 1; // try fewer queries
            } else {
                left = mid + 1;  // need more
            }
        }
        return ans;
    }
};
