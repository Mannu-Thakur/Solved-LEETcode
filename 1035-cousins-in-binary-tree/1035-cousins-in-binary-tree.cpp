class Solution {
    // Helper function to find depth and parent
    void dfs(TreeNode* root, int val, int depth, TreeNode* parent, int& outDepth, TreeNode*& outParent) {
        if (!root) return;
        if (root->val == val) {
            outDepth = depth;
            outParent = parent;
            return;
        }
        dfs(root->left, val, depth + 1, root, outDepth, outParent);
        dfs(root->right, val, depth + 1, root, outDepth, outParent);
    }

public:
    bool isCousins(TreeNode* root, int x, int y) {
        int dx = -1, dy = -1;
        TreeNode *px = nullptr, *py = nullptr;

        dfs(root, x, 0, nullptr, dx, px);
        dfs(root, y, 0, nullptr, dy, py);

        return (dx == dy) && (px != py); // Same level, different parents
    }
};
