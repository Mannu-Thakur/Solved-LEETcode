/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
    void solve(TreeNode* root, vector<int>& temp) {
        TreeNode* curr = root;

        while (curr) {
            if (curr->left == nullptr) {
                temp.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr) {
                    pred = pred->right;
                }

                if (pred->right == nullptr) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = nullptr;
                    temp.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        if (!root)
            return nullptr;

        vector<int> temp;
        solve(root, temp);

        TreeNode* dummy = new TreeNode(-1);  
        TreeNode* node = dummy;

        for (int val : temp) {
            node->right = new TreeNode(val);
            node = node->right;
        }

        return dummy->right;
    }
};