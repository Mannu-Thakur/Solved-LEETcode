 
class Solution {
public:
    long long maximumHappinessSum(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());

        long long ans = 0;

        for (int i = 0; i < k; ++i) {
            int val = nums[i] - i;
            if (val <= 0) break;
            ans += val;
        }

        return ans;
    }
};
