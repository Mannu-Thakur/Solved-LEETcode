class Solution {
public:
    int dfs(TreeNode* root, vector<int>& res) {
        if (!root) return 0;

        int leftSum = dfs(root->left, res);
        int rightSum = dfs(root->right, res);
        int totalSum = root->val + leftSum + rightSum;

        res.push_back(totalSum);
        return totalSum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        dfs(root, res);

        unordered_map<int, int> mp;
        for (int i = 0; i < res.size(); ++i) {
            mp[res[i]]++;
        }

        int f = 0;
        for (auto& m : mp) {
            if (m.second > f) {
                f = m.second;
            }
        }

        vector<int> ans;
        for (auto& k : mp) {
            if (k.second == f) {
                ans.push_back(k.first);
            }
        }

        return ans;
    }
};
