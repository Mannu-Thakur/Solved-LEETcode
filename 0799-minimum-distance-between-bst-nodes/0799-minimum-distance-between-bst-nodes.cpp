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
    void solve(TreeNode* root,  int &prev, int &minDiff){
        if(!root) return;

        solve(root->left, prev,minDiff);

        if(prev != -1){
            minDiff = min(minDiff,abs( root->val - prev));
        }
        prev = root->val;
        solve(root->right, prev, minDiff);
    }
public:
    int minDiffInBST(TreeNode* root) {
        if(!root) return 0;
        int prev = -1;
        int minDiff = INT_MAX;
        solve(root, prev, minDiff);
        return minDiff;
    }
};