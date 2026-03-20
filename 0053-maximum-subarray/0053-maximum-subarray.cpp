class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        if(n == 1 ) return nums[0];

        int x = *max_element(nums.begin(), nums.end());
        if(x < 0) return x;

        int sum = 0;
        int ans = 0;

        for(int i=0; i<n; ++i){
            sum += nums[i];

            if(sum < 0){
                sum = 0;
            }

            ans = max(ans, sum);
        }

        return ans;
    }

};