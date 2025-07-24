class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);

         
        int fullRepeats = target / totalSum;
        int remainingTarget = target % totalSum;
 
        if (remainingTarget == 0) return fullRepeats * n;
  
 
        int minLen = INT_MAX;
        int start = 0;
        long long sum = 0;

        for (int end = 0; end < 2 * n; ++end) {
            sum += nums[end % n];

            while (sum > remainingTarget && start <= end) {
                sum -= nums[start % n];
                ++start;
            }

            if (sum == remainingTarget) {
                minLen = min(minLen, end - start + 1);
            }
        }

        return (minLen == INT_MAX) ? -1 : minLen + fullRepeats * n;
    }
};
