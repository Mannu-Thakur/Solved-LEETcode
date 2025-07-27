class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;

        bool yes = false;
        int cnt = n-1;
        for(int i=0; i<n-1; ++i){
            if(nums[i] <= nums[i+1])cnt--;
            if(cnt == 0) yes = true;
        }

        cnt = n-1;
        for(int i=0; i<n-1; ++i){
            if(nums[i] >= nums[i+1]) cnt--;
            if(cnt == 0) yes = true;
        }

        return yes == true;
    }
};