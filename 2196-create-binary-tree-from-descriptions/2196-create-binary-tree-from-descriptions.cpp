class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childs;

        for (auto& each : descriptions) {

            int parent = each[0];
            int child = each[1];

            if (mp.find(parent) == mp.end()) {
                mp[parent] = new TreeNode(parent);
            }

            if (mp.find(child) == mp.end()) {
                mp[child] = new TreeNode(child);
            }

            if (each[2]) {
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }

            childs.insert(child);
        }

        for (auto& it : mp) {
            if (childs.find(it.first) == childs.end()) {
                return it.second;
            }
        }

        return nullptr;
    }
};