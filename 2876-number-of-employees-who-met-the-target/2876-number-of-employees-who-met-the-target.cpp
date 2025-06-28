class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for(auto &f: nums ){
            if(f >= target){
                ans++;
            }
        }
        return ans;
    }
};