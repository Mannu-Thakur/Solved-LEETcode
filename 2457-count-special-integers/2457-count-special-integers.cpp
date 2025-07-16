// class Solution {
//     bool solve(int num){
//         unordered_map<int, int> mp;
//         int cnt = 0;

//         while(num > 0){
//             int l = num % 10;
//             mp[l]++;
//             num /= 10;
//             cnt++;
//         }

//         return cnt == mp.size();
//     }
// public:
//     int countSpecialNumbers(int n) {
//         int cnt = 0;
        
//         for(int i = 1; i <= n; ++i){
//             if(solve(i)){
//                 cnt++;
//             }
//         }

//         return cnt;
//     }
// };


class Solution {
public:
    int dp[11][2][1024]; // idx, tight, mask

    int dfs(const string &s, int idx, bool tight, int mask) {
        if (idx == s.size()) return 1;  // valid number formed

        if (dp[idx][tight][mask] != -1) return dp[idx][tight][mask];

        int limit = tight ? s[idx] - '0' : 9;
        int ans = 0;

        for (int digit = 0; digit <= limit; ++digit) {
            if (mask == 0 && digit == 0) {  // skip leading zero counting
                ans += dfs(s, idx + 1, tight && (digit == limit), mask);
            } else if (!(mask & (1 << digit))) {  // digit not used yet
                ans += dfs(s, idx + 1, tight && (digit == limit), mask | (1 << digit));
            }
        }

        return dp[idx][tight][mask] = ans;
    }

    int countSpecialNumbers(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return dfs(s, 0, 1, 0) - 1;  // subtract 1 for excluding 0
    }
};
