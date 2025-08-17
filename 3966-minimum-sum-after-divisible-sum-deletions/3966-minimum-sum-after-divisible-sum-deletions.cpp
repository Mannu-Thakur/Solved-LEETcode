class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n = nums.size();

         unordered_map<int, int> indexMap{{0, n}}; 

         vector<long long> dp(n + 1, 0);

        long long sum = 0;

         for (int i = n - 1; i >= 0; i--) {
            sum += nums[i];

            int mod = sum % k;
            if (mod < 0) mod += k;

             dp[i] = nums[i] + dp[i + 1]; 

             if (indexMap.count(mod)) {
                dp[i] = min(dp[i], dp[indexMap[mod]]);
            }

             indexMap[mod] = i;
        }

        return dp[0];
    }
};