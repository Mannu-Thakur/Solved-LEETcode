class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;

        for(auto &f: nums){
            if(f < k){
                cnt++;
            }
        }
        return cnt;
    }

};