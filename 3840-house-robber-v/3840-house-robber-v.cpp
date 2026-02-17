
// brute force on ( cant pick same previously picked color ) ---------------------------

// class Solution {

//     typedef long long ll;

//     ll solve(vector<int>& nums, vector<int>& colors, 
//              int n, int ind, int prevColor) {

//         // base case
//         if (ind >= n) return 0;

//         ll pick = 0;

//         // take only if color allowed
//         if (prevColor == -1 || prevColor != colors[ind]) {
//             pick = nums[ind] + 
//                    solve(nums, colors, n, ind + 1, colors[ind]);
//         }

//         ll not_pick = solve(nums, colors, n, ind + 1, prevColor);

//         return max(pick, not_pick);
//     }

// public:
//     long long rob(vector<int>& nums, vector<int>& colors) {
//         int n = nums.size();
//         return solve(nums, colors, n, 0, -1);
//     }
// };


// brute force on ( cant pick on same adjacent color ) ---------------------
// estriction is on adjacent positions in array, not on previously picked color.
class Solution {
    typedef long long ll;

    ll solve(vector<int>& nums, vector<int>& colors,
             int n, int ind, bool prevTaken,
             vector<vector<ll>>& dp) {

        if (ind >= n) return 0;

        if (dp[ind][prevTaken] != -1)
            return dp[ind][prevTaken];

        // Not pick
        ll not_pick = solve(nums, colors, n,
                            ind + 1, false, dp);

        // Pick
        ll pick = 0;

        // Safe check for ind == 0
        if (!prevTaken || ind == 0 ||
            colors[ind] != colors[ind - 1]) {

            pick = nums[ind] +
                   solve(nums, colors, n,
                         ind + 1, true, dp);
        }

        return dp[ind][prevTaken] =
               max(pick, not_pick);
    }

public:
    long long rob(vector<int>& nums,
                  vector<int>& colors) {

        int n = nums.size();

        // dp[ind][prevTaken]
        vector<vector<ll>> dp(n,
            vector<ll>(2, -1));

        return solve(nums, colors, n,
                     0, false, dp);
    }
};
