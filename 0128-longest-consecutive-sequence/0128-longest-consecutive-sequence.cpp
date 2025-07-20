class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int len = 1;
        int curLen = 1;

        sort(nums.begin(), nums.end());
        for(int i = 1; i<n; ++i){
            if(nums[i] == nums[i-1]) continue;
            if(nums[i] == nums[i-1]+1){
                curLen++;
            }
            else{
                len = max(len, curLen);
                curLen=1;
            }
        }
        return max(len, curLen);
    }
};