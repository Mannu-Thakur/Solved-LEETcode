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
    pair<int, TreeNode*> solve(TreeNode* root){
        if(!root) return {0, nullptr};

        auto left = solve(root->left);
        auto right = solve(root->right);

        int l_ht = left.first;
        int r_ht = right.first;

        if(l_ht == r_ht){
            return {l_ht + 1, root};
        }else if(l_ht > r_ht){
            return {l_ht + 1, left.second};
        }else{
            return {r_ht + 1, right.second};
        }
        
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) return nullptr;

       return solve(root).second;
    }
};