class Solution {
    vector<vector<int>>res;
    void generate(vector<int>&ans, vector<int>&nums, int i){
        if(i == nums.size()){
            res.push_back(ans);
            return;
        }

        generate(ans, nums, i+1);

        ans.push_back(nums[i]);
        generate(ans, nums, i+1);
        ans.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        generate(ans, nums, 0);
        return res;

    }
};