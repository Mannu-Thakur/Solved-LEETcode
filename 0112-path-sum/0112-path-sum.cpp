class Solution {
    bool dfs(TreeNode* root, int tsum) {
        if (!root) return false;

        tsum -= root->val;

        // Leaf node
        if (!root->left && !root->right)
            return tsum == 0;

        return dfs(root->left, tsum) || dfs(root->right, tsum);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        return dfs(root, targetSum);
    }
};