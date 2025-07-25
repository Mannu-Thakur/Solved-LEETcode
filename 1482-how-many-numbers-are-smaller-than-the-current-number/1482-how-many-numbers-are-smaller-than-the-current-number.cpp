class Solution {
    int solve(int num, vector<int>&nums){
        int n = nums.size();
        int cnt = 0;

        for(int i=0; i<n; ++i){
            if(nums[i] < num){
                cnt++;
            }
        }
        return cnt;
    }
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
         
        int n = nums.size();
        vector<int>res(n, 0);

        
        for(int i=0; i<n; ++i){
           res[i] = solve(nums[i], nums);
        }
        return res;
    }
};