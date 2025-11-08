class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        sort(nums.begin(), nums.end());
        int a = nums[n-1];
        for(int i=0; i<n; ++i){
            cnt += (a - nums[i]);
        }
        return cnt;
    }
};