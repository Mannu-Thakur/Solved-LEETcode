class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return dfs(root, 0, limit);
    }

    TreeNode* dfs(TreeNode* node, int sum, int limit) {
        if (!node) return nullptr;

        sum += node->val;

         if (!node->left && !node->right) {
            return (sum < limit) ? nullptr : node;
        }
         node->left = dfs(node->left, sum, limit);
        node->right = dfs(node->right, sum, limit);

         if (!node->left && !node->right) return nullptr;

        return node;
    }
};
