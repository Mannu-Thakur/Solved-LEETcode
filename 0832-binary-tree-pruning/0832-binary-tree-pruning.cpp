class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return nullptr;

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if (root->val == 0 && !root->left && !root->right) {
            return nullptr; // prune the node
        }

        return root; // keep the node
    }
};
