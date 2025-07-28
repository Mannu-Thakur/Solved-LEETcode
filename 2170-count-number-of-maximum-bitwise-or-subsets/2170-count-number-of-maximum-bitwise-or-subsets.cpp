class Solution {
    void solve(vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans, int ind, int n) {
        if (ind >= n) {
            ans.push_back(temp);
            return;
        }

        // Include nums[ind]
        temp.push_back(nums[ind]);
        solve(temp, nums, ans, ind + 1, n);
        temp.pop_back();

        // Exclude nums[ind]
        solve(temp, nums, ans, ind + 1, n);
    }

    int ors(vector<int>& nums) {
        int o_r = 0;
        for (auto &f : nums) {
            o_r |= f;
        }
        return o_r;
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp;
        vector<vector<int>> ans;

        solve(temp, nums, ans, 0, n);

        int maxOr = 0;
        for (auto &f : ans) {
            maxOr = max(maxOr, ors(f));
        }

        int count = 0;
        for (auto &f : ans) {
            if (ors(f) == maxOr) {
                count++;
            }
        }

        return count;
    }
};
