class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        dfs(root, sum);
        return sum;
    }

private:
    int dfs(TreeNode* root, int& sum) {
        if (!root) return 0;

        int left = max(0, dfs(root->left, sum));
        int right = max(0, dfs(root->right, sum));

        sum = max(sum, left + right + root->val);

        return max(left, right) + root->val;
    }
};
