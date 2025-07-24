class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        int mini = nums[0];  
        for(int i = 1; i < n; ++i){
            mini = min(mini, nums[i]);
        }

        for(int i = 0; i < n; ++i){
            cnt += (nums[i] - mini);
        }
        return cnt;
    }
};
