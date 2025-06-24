class Solution {
    void pushLeft(TreeNode* node, stack<TreeNode*>& st) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;
        vector<int> result;

        pushLeft(root1, s1);
        pushLeft(root2, s2);

        while (!s1.empty() || !s2.empty()) {
            stack<TreeNode*>& current = 
                s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val) ? s1 : s2;

            TreeNode* node = current.top();
            current.pop();
            result.push_back(node->val);
            pushLeft(node->right, current);
        }

        return result;
    }
};
