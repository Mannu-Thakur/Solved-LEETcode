class Solution {
public:
    unordered_map<string, vector<TreeNode*>> subtrees;
    vector<TreeNode*> res;

    string dfs(TreeNode* node) {
        if (!node) return "null";

        string s = to_string(node->val) + "," + dfs(node->left) + "," + dfs(node->right);

        if (subtrees[s].size() == 1) {
            res.push_back(node);
        }
        subtrees[s].push_back(node);
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return res;
    }
};
