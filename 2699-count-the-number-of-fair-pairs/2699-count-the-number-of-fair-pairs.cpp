// 'class Solution {
// public:
//     long long countFairPairs(vector<int>& nums, int lower, int upper) {
//         multiset<int> seen;
//         long long count = 0;

//         for (int x : nums) {
//             // Count how many previous numbers y satisfy:
//             // lower - x <= y <= upper - x
//             auto low = seen.lower_bound(lower - x);
//             auto high = seen.upper_bound(upper - x);
//             count += distance(low, high);

//             // Insert current number for future comparisons
//             seen.insert(x);
//         }

//         return count;
//     }
// };
// '



class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long count = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int left = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int right = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            count += (right - left);
        }

        return count;
    }
};
