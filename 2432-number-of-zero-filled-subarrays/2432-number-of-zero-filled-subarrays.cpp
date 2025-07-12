class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp;
        int len = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                len++;
            } else {
                if (len > 0) {
                    temp.push_back(len); // push the length of the 0-group
                    len = 0;             // reset the length
                }
            }
        }

        // In case the array ends with a zero streak
        if (len > 0) {
            temp.push_back(len);
        }

        long long ans = 0;
        for (auto &f : temp) {
            ans += (1LL * f * (f + 1)) / 2; // Cast to long long to prevent overflow
        }

        return ans;
    }
};
