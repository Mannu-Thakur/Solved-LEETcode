class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            TreeNode* xParent = nullptr;
            TreeNode* yParent = nullptr;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();

                if (node->left) {
                    q.push(node->left);
                    if (node->left->val == x) xParent = node;
                    if (node->left->val == y) yParent = node;
                }

                if (node->right) {
                    q.push(node->right);
                    if (node->right->val == x) xParent = node;
                    if (node->right->val == y) yParent = node;
                }
            }

            // If both found at same level
            if (xParent && yParent) {
                return xParent != yParent; // cousins if different parents
            }

            // If only one is found at this level, return false
            if ((xParent && !yParent) || (!xParent && yParent)) {
                return false;
            }
        }

        return false;
    }
};
