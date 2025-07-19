class Solution {
    void collect(TreeNode* root, vector<int>& nodes) {
        if (root == nullptr) {
            return;
        }
        collect(root->left, nodes);
        nodes.push_back(root->val);
        collect(root->right, nodes);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nodes;
        collect(root, nodes);
        int n = nodes.size();
        
        if (k > n) return -1; 
        priority_queue<int> q;

        for (int i = 0; i < k; ++i) {
            q.push(nodes[i]);
        }

        for (int i = k; i < n; ++i) {
            if (q.top() > nodes[i]) {
                q.pop();
                q.push(nodes[i]);
            }
        }
        return q.top();
    }
};
