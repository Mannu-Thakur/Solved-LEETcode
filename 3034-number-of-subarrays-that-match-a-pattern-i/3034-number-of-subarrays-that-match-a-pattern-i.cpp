class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();

        int ans = 0;

        for (int i = 0; i + m < n; i++) {
            bool ok = true;

            for (int j = 0; j < m; j++) {
                if (pattern[j] == 1) {
                    if (!(nums[i + j + 1] > nums[i + j])) {
                        ok = false;
                        break;
                    }
                }
                else if (pattern[j] == 0) {
                    if (!(nums[i + j + 1] == nums[i + j])) {
                        ok = false;
                        break;
                    }
                }
                else {  
                    if (!(nums[i + j + 1] < nums[i + j])) {
                        ok = false;
                        break;
                    }
                }
            }

            if (ok) ans++;
        }

        return ans;
    }
};