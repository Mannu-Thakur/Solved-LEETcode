class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int s = 0;
        int e = 0;
        int l = 0;
        for( e=0; e<n; ++e){
            while(nums[e] - nums[s] > 1){
                s++;
            }
            if( nums[e] - nums[s] == 1){
                l = max(l, e-s+1);
            }
        }
        return l;
    }
};