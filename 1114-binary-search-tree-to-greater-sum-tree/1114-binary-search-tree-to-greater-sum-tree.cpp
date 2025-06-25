class Solution {
    void solve(TreeNode* root, int &sum){
        if(!root) return;

        solve(root->right, sum);         // Process right subtree
        sum += root->val;                // Update running sum
        root->val = sum;                 // Update current node
        solve(root->left, sum);          // Process left subtree
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        solve(root, sum);
        return root;
    }
};
