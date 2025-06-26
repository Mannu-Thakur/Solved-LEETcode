class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minpro = nums[0];
        int maxpro = nums[0];
        int res = nums[0];


        for(int i =1; i<n; ++i){
            if(nums[i] < 0){
                swap(minpro, maxpro);
            }

            minpro = min(nums[i], nums[i]*minpro);
            maxpro = max(nums[i], nums[i]*maxpro);
            res = max(res, maxpro);
        }
        
       return res;

    }
};