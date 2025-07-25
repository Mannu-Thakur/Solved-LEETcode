class Solution {
    pair<int, TreeNode*> solve(TreeNode* root){
        if(!root) return {0, nullptr};

        auto left = solve(root->left);
        auto right = solve(root->right);

        int left_depth = left.first;
        int right_depth = right.first;

        if(left_depth == right_depth){
            return {left_depth + 1, root};
        }else if(left_depth > right_depth){
            return {left_depth + 1,  left.second};
        }else{
            return {right_depth + 1, right.second}; // ✅ fixed
        }
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return nullptr;

        return solve(root).second;
    }
};
