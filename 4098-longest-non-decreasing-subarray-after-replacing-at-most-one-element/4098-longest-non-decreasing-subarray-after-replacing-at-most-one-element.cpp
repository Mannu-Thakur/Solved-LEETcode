class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;

        vector<int> left(n,1), right(n,1);

        for(int i=1;i<n;i++){
            if(nums[i] >= nums[i-1]) left[i] = left[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i] <= nums[i+1]) right[i] = right[i+1]+1;
        }

        int ans = *max_element(left.begin(), left.end()); // no replace case

        for(int i=0;i<n;i++){
            int l = (i? left[i-1]:0);
            int r = (i<n-1? right[i+1]:0);
            ans = max(ans, l+1);
            ans = max(ans, r+1);
            if(i>0 && i<n-1 && nums[i-1] <= nums[i+1]){
                ans = max(ans, l+1+r);
            }
        }
        return ans;
    }
};
