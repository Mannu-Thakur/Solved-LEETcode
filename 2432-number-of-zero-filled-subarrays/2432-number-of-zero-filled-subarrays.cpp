class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;  // changed to long long
        long long len = 0;  // also long long, because len*(len+1)/2 can overflow int

        int i = 0;
        while (i < n) {
            if (nums[i] == 0) {
                len++;
            } else {
                if (len > 0) {
                    ans += len * (len + 1) / 2;
                    len = 0;
                }
            }
            i++;
        }

        ans += len * (len + 1) / 2;  // add the last streak
        return ans;
    }
};
