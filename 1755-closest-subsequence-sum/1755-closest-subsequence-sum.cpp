class Solution {
    vector<long long> findAllSums(vector<int>& nums, int start, int end) {
        // handle empty range
        if(start > end) return {0};

        int n = end - start + 1;
        vector<long long> res;

        for(int mask = 0; mask < (1 << n); mask++) {
            long long sum = 0;
            for(int j = 0; j < n; j++) {
                if(mask & (1 << j)) {
                    sum += nums[start + j];
                }
            }
            res.push_back(sum);
        }
        return res;
    }

public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();

        // split array
        auto left = findAllSums(nums, 0, n/2 - 1);
        auto right = findAllSums(nums, n/2, n - 1);

        // sort right half for binary search
        sort(right.begin(), right.end());

        long long ans = LLONG_MAX;

        for(long long x : left) {
            long long target = goal - x;

            auto it = lower_bound(right.begin(), right.end(), target);

            // check closest >= target
            if(it != right.end()) {
                ans = min(ans, abs(goal - (x + *it)));
            }

            // check just smaller
            if(it != right.begin()) {
                --it;
                ans = min(ans, abs(goal - (x + *it)));
            }

            // best possible
            if(ans == 0) return 0;
        }

        return (int)ans;
    }
};