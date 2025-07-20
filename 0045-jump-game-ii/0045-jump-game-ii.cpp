class Solution {
        int find(vector<int>&nums, int n, int jumps, int ind){
            if(ind >= n-1) return jumps;
            int l=0;
            int r=0;
            int far = 0;
            while( r < n-1){
            for(int i=l; i<=r;++i){
                far=max(far, i+nums[i]);
            }
           
            l=r+1;
            r=far;
            jumps++;
            
        }
        return jumps;
        }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
       return find(nums, n, 0, 0);
        
    }
};