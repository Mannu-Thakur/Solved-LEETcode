class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mpp;
        int cnt = 0;

        //nums[i] - x = k => x = nums[i] - k
        for(int i=0; i<n; ++i){
            cnt += mpp[nums[i] + k];
            cnt += mpp[nums[i] - k];
            mpp[nums[i]]++;
        }

        return cnt;



    }
};