/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){
            return nullptr;
        }
       
       if( root == p || root == q){
        return root;
       }

       TreeNode* cur1 = lowestCommonAncestor(root->left, p,q);
       TreeNode* cur2 = lowestCommonAncestor(root->right, p,q);

       if(cur1 && cur2){
        return root;
       }
       else if(cur2){
        return cur2;
       }
       else if( cur1){
        return cur1;;
       }
       else{
        return nullptr;
       }

    }
};