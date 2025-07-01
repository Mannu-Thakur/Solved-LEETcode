class Solution {
public:
    unordered_map<int, vector<TreeNode*>> dp;

    vector<TreeNode*> allPossibleFBT(int n) {
        if (dp.count(n)) return dp[n];
        vector<TreeNode*> res;

        if (n == 1) {
            res.push_back(new TreeNode(0));
            return dp[n] = res;
        }

        for (int left = 1; left < n; left += 2) {
            int right = n - 1 - left;
            vector<TreeNode*> leftTrees = allPossibleFBT(left);
            vector<TreeNode*> rightTrees = allPossibleFBT(right);

            for (TreeNode* l : leftTrees) {
                for (TreeNode* r : rightTrees) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }

        return dp[n] = res;
    }
};
