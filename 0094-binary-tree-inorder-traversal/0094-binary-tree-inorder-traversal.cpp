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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == nullptr){
            return  ans;
        }

            if(root->left != nullptr){
            vector<int>left = inorderTraversal(root->left);
            ans.insert(ans.end(), left.begin(), left.end());
            }

            ans.push_back(root->val);

            if(root->right){
            vector<int>right = inorderTraversal(root->right);
            ans.insert(ans.end(), right.begin(), right.end());
           }
        return ans;
    }
};