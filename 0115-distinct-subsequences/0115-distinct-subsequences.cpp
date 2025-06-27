// class Solution {
//     bool isSame(string &t , int m, int ind, string &str) {
//         if (str.length() != m) return false; 
//         for (int i = 0; i < m; i++) {
//             if (t[i] != str[i]) {
//                 return false;
//             }
//         }
//         return true;
//     }

//     void solve(string &s, string &t, int n, int m, int inds, int indt, int &cnt, string str) {
//         if (inds == n) {  
//             if (isSame(t, m, indt, str)) {
//                 cnt++;
//             }
//             return;
//         }
      
      
//         solve(s, t, n, m, inds + 1, indt, cnt, str + s[inds]);

//         solve(s, t, n, m, inds + 1, indt, cnt, str);
//     }

// public:
//     int numDistinct(string s, string t) {
//         int n = s.length();
//         int m = t.length();
//         int cnt = 0;
//         solve(s, t, n, m, 0, 0, cnt, "");
//         return cnt;
//     }
// };

class Solution {
    int solve(string &s, string &t, int n, int m, int inds, int indt, vector<vector<int>> &dp) {
        if (indt == m) return 1;  
        if (inds == n) return 0;  
        
        if (dp[inds][indt] != -1) return dp[inds][indt]; 

        int count = 0;
        
        if (s[inds] == t[indt]) {
            count += solve(s, t, n, m, inds + 1, indt + 1, dp);
        }
        count += solve(s, t, n, m, inds + 1, indt, dp);

        return dp[inds][indt] = count;
    }

public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(s, t, n, m, 0, 0, dp);
    }
};
