class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];

            int mod = sum % k;
            if (mod < 0) {
                mod += k; 
            }

            if (mpp.find(mod) != mpp.end()) {
                ans += mpp[mod]; 
            }

            mpp[mod]++;
        }

        return ans;
    }
};
