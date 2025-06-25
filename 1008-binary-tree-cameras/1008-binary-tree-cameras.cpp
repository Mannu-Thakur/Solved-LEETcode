class Solution {
    int cameras = 0;

    int dfs(TreeNode* node) {
        if (!node) return 2;

        int left = dfs(node->left);
        int right = dfs(node->right);

        if (left == 0 || right == 0) {
            cameras++;
            return 1; // Has camera
        }

        if (left == 1 || right == 1) {
            return 2; // Covered
        }

        return 0; // Not covered
    }

public:
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) {
            cameras++;
        }
        return cameras;
    }
};
