class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> temp;

             for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                 temp.push_back(node);

                 if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

             if (level % 2 == 1) {
                int i = 0, j = temp.size() - 1;
                while (i < j) {
                    swap(temp[i]->val, temp[j]->val);
                    ++i;
                    --j;
                }
            }

            level++;  // move to next level
        }

        return root;
    }
};
