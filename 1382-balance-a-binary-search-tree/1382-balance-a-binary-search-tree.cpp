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

   TreeNode* buildBalanced(vector<int>& temp, int l, int r) {
    if (l > r) return nullptr;

    int mid = l + (r - l) / 2;
    TreeNode* root = new TreeNode(temp[mid]);

    root->left  = buildBalanced(temp, l, mid - 1);
    root->right = buildBalanced(temp, mid + 1, r);

    return root;
}
 
   void inorder(TreeNode* root, vector<int>& temp) {
    if (!root) return;
    inorder(root->left, temp);
    temp.push_back(root->val);
    inorder(root->right, temp);
}

public:
   TreeNode* balanceBST(TreeNode* root) {
    if (!root) return nullptr;

    vector<int> temp;
    inorder(root, temp);

    return buildBalanced(temp, 0, temp.size() - 1);
}

};