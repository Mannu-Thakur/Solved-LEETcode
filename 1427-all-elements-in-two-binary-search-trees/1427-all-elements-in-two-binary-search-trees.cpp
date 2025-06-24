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
    void solve(TreeNode* root, vector<int>& res) {
        if (!root) return;
        res.push_back(root->val);         // Preorder traversal
        solve(root->left, res);
        solve(root->right, res);
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        
        if (!root1 && !root2) {
            return {};
        }
        else if (!root1) {
            solve(root2, res);
        }
        else if (!root2) {
            solve(root1, res);
        }
        else {
            solve(root1, res);
            vector<int> temp;
            solve(root2, temp);
            res.insert(res.end(), temp.begin(), temp.end());
        }

        sort(res.begin(), res.end());  // Sort after collecting all values
        return res;
    }
};
