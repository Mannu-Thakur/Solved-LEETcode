class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = nums.size();
        for(int i = 0;i < nums.size();i++) {
            if(i != nums[i]) ans = min(ans, (nums[i]&i));
        }
        return (ans == nums.size())? 0: ans;
    }
};