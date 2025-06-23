class Solution {
    int dfs(TreeNode* root, int &cnt) {
        if (!root) return 0;

        int l = 0, r = 0;

        if (root->left) {
            l = dfs(root->left, cnt);
        }

        if (root->right) {
            r = dfs(root->right, cnt);
        }

        root->val = l + r + (root->val - 1);
        cnt += abs(root->val);
        
        return root->val;
    }

public:
    int distributeCoins(TreeNode* root) {
        if (!root) return 0;
        int moves = 0;
        dfs(root, moves);
        return moves;
    }
};
