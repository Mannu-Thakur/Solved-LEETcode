class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        bool found = false;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                for(int k = j+1; k<n; ++k){
                    if(nums[i] < nums[j] && nums[k] < nums[j]){
                        ans = min(ans, nums[i] + nums[j] + nums[k]);
                        found = true;
                    }
                }
            }
        }
        return found ? ans : -1;  // return -1 if no triplet exists
    }
};
