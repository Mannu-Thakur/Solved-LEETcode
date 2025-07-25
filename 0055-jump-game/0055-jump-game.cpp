class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] == 0 && n==1) return true ;
        if(nums[0] == 0 && n != 1) return false;

        int maxInd = 0;

        for(int i=0; i<n; ++i){
            maxInd = max(maxInd, i+nums[i]);
            if(i >= maxInd) return false;
            if(maxInd >= n-1) return true;
        } 

        return false;   
    }
};