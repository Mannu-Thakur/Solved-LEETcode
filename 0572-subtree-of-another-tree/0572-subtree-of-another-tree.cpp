class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) return subRoot == NULL;

        if (isSameTree(root, subRoot)) return true;

        // Check in left and right subtree
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) return true;
        if (s == NULL || t == NULL) return false;
        if (s->val != t->val) return false;

        // Recurse for left and right
        return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
};