class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        // int s = 0;
        // int e = n - 1;
        // while(s < e){
        //     int m = s + (e - s) / 2;
        //     if(nums[m] > nums[e]){
        //      s = m + 1;
        //     }

        //     else {
        //     e = m;
        //     }
        // }
        // return nums[s];

        sort(nums.begin(), nums.end());
        return nums[0];
    }
};