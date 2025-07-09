class Solution {
    TreeNode* solve(vector<int>& nums, int s, int end) {
        if (s > end) return nullptr;

        int maxi = INT_MIN;
        int ind = s;

        for (int i = s; i <= end; ++i) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                ind = i;
            }
        }

        TreeNode* root = new TreeNode(maxi);
        root->left = solve(nums, s, ind - 1);
        root->right = solve(nums, ind + 1, end);
        return root;
    }

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};
