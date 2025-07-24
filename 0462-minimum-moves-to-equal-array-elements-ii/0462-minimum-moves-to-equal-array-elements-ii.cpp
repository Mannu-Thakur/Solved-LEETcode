class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int med = nums[nums.size()/2];
        int cnt = 0;
        for(int num : nums){
            cnt += abs(num - med);
        }
        return cnt;
    }
};
