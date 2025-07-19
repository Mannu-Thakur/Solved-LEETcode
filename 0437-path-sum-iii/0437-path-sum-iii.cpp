class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> mpp; 
        mpp[0] = 1;  
        return solve(root, targetSum, 0, mpp);
    }

    int solve(TreeNode* root, long long targetSum, long long currSum, unordered_map<long long, int>& mpp) {
        if (!root) return 0;
        int cnt = 0;
        
        currSum += root->val;
        long long req = currSum - targetSum;
  
        if (mpp.find(req) != mpp.end())
            cnt += mpp[req];

        
        mpp[currSum]++;
       
        cnt += solve(root->left, targetSum, currSum, mpp);
        cnt += solve(root->right, targetSum, currSum, mpp);

        
        mpp[currSum]--;

        return cnt;
    }
};
