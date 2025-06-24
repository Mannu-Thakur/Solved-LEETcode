class Solution {
    void inorder(TreeNode* root, int &prev, int &minDiff) {
        if (!root) return;

        inorder(root->left, prev, minDiff);

        if (prev != -1) {
            minDiff = min(minDiff, abs(root->val - prev));
        }
        prev = root->val;

        inorder(root->right, prev, minDiff);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        int prev = -1;
        inorder(root, prev, minDiff);
        return minDiff;
    }
};
