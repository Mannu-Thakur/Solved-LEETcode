class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> bad(n, 0); // bad[i] = 1 if nums[i] and nums[i+1] have same parity

        for (int i = 0; i < n - 1; ++i) {
            if ((nums[i] % 2) == (nums[i + 1] % 2))
                bad[i] = 1;
        }

        // Build prefix sum of bad[]
        vector<int> prefix(n, 0);
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + bad[i - 1];
        }

        vector<bool> res;
        for (auto& q : queries) {
            int a = q[0], b = q[1];
            // Check if there is any bad pair in range [a, b - 1]
            if (prefix[b] - prefix[a] == 0)
                res.push_back(true);
            else
                res.push_back(false);
        }

        return res;
    }
};
