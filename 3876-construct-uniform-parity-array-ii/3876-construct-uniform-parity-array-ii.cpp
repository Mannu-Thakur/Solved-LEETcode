// class Solution {
// public:

//     bool solve_even(vector<int>& nums) {
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {

//             // if already even → fine
//             if (nums[i] % 2 == 0) continue;

//             // if odd → try to convert using smaller odd
//             bool ok = false;

//             for (int j = 0; j < n; j++) {
//                 if (i == j) continue;

//                 if (nums[j] < nums[i] && nums[j] % 2 == 1) {
//                     ok = true;
//                     break;
//                 }
//             }

//             if (!ok) return false;
//         }

//         return true;
//     }

//     bool solve_odd(vector<int>& nums) {
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {

//             // if already odd → fine
//             if (nums[i] % 2 == 1) continue;

//             // if even → try to convert using smaller odd
//             bool ok = false;

//             for (int j = 0; j < n; j++) {
//                 if (i == j) continue;

//                 if (nums[j] < nums[i] && nums[j] % 2 == 1) {
//                     ok = true;
//                     break;
//                 }
//             }

//             if (!ok) return false;
//         }

//         return true;
//     }

//     bool uniformArray(vector<int>& nums) {
//         return solve_even(nums) || solve_odd(nums);
//     }
// };


class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int minOdd = INT_MAX;
        bool hasOdd = false;

        // find smallest odd
        for (int x : nums) {
            if (x % 2 == 1) {
                hasOdd = true;
                minOdd = min(minOdd, x);
            }
        }

        // if no odd → already all even
        if (!hasOdd) return true;

        // check all evens
        for (int x : nums) {
            if (x % 2 == 0 && x <= minOdd)
                return false;
        }

        return true;
    }
};