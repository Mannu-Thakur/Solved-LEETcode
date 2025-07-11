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
    void dfs(TreeNode* root, int &cnt, int last){
        if(!root) {
            return;
        }

        if(root->val >= last){
            cnt++;
            last = root->val;
        }

        dfs(root->left, cnt, last);
        dfs(root->right, cnt, last);


    }
public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;

         
        int cnt = 0;
        dfs(root, cnt, root->val);
        return cnt;
    }
};
 