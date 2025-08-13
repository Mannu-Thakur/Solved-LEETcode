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
    TreeNode* solve(vector<int>&temp, int s, int e){
        if(s > e ) return nullptr;
        int mid = s + (e - s)/2;
        TreeNode* root = new TreeNode(temp[mid]);

        root->left = solve(temp, s, mid-1);
        root->right = solve(temp, mid+1, e);
        return root;
    }
    void solve(TreeNode* root, vector<int>&temp){
        if(!root) return;
        
        solve(root->left, temp);
        temp.push_back(root->val);
        solve(root->right, temp);
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return nullptr;
        vector<int>temp;
        solve(root, temp);

        return solve(temp, 0 , temp.size()-1);
        
    }
};