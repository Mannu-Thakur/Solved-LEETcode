class Solution {
    void generate(int n, vector<int>&nums, int ind, vector<vector<int>>&ans){
        if( ind == n){
            ans.push_back(nums);
            return;
        }

      for(int i = ind; i<n; ++i){
        swap(nums[ind], nums[i]);
        generate(n,nums,ind+1,ans);
        swap(nums[ind], nums[i]);
      }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        generate(n,nums, 0, ans);
        return ans;
        }
};