class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        // preSum[r-1] - preSum[l] = sum from l to r
        // ( preSum[r-1] - preSum[l] ) % k == 0 
        // preSum[r-1] % k == preSum[l] % k

        unordered_map<int, int>mpp;
        mpp[0] = 1;
        int sum = 0;
        int ans = 0;

        for(int r = 0; r < n; ++r){
            sum += nums[r];

            int mod = sum % k;

            if(mod < 0){
                mod += k;
            }

            if(mpp.find(mod) != mpp.end()){
                ans += mpp[mod];
            } 

            mpp[mod]++;
        }
        
        return ans;
    }

};