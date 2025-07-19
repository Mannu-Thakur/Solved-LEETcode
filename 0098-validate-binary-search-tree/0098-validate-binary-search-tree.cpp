/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool solve(TreeNode* root, long maxx, long minn) {
        if (!root) return true;
        if (root->val <= minn || root->val >= maxx) return false;
        return solve(root->left, root->val, minn) && solve(root->right, maxx, root->val);
    }

public:
    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MAX, LONG_MIN);
    }
};
