class Solution {
public:
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder,
                              int inStart, int inEnd, int& postIndex, unordered_map<int, int>& inMap) {
        if (inStart > inEnd) return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inMap[rootVal];

        // Important: build right before left (due to postorder's root-right-left pattern in reverse)
        root->right = buildTreeHelper(inorder, postorder, inIndex + 1, inEnd, postIndex, inMap);
        root->left = buildTreeHelper(inorder, postorder, inStart, inIndex - 1, postIndex, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int postIndex = n - 1;
        unordered_map<int, int> inMap;

        // Map inorder values to their indices for O(1) access
        for (int i = 0; i < n; ++i) {
            inMap[inorder[i]] = i;
        }

        return buildTreeHelper(inorder, postorder, 0, n - 1, postIndex, inMap);
    }
};
