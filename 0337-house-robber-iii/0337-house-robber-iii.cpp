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
    pair<int, int>solve(TreeNode* root){
        if(!root) return {0, 0};

        auto l = solve(root->left);
        auto r = solve(root->right);

        // taking the root
        int pick = root->val + l.second + r.second;

        // not taking the root
        int notpick = 0 + max(l.first , l.second) + max(r.first, r.second);
        
        return {pick, notpick};

    }
public:
    int rob(TreeNode* root) {
        if(!root) return 0;

        auto res = solve(root);
        return max(res.first, res.second);
    }
};