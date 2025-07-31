 

class Solution {
    string solve(string &s) {   // Your original compression helper (kept as requested)
        int n = s.length();
        string temp = "";
        int read = 0;

        while (read < n) {
            int cnt = 0;
            char curr = s[read];
            while (read < n && s[read] == curr) {
                cnt++;
                read++;
            }
            temp.push_back(curr);
            temp += to_string(cnt);   // ✅ fixed bug for multi-digit counts
        }
        return temp;
    }

public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(k+1, INT_MAX));

        // Base case
        for (int j = 0; j <= k; j++) dp[n][j] = 0;

        // Bottom-up DP
        for (int i = n - 1; i >= 0; i--) {
            for (int del = 0; del <= k; del++) {
                int cnt[26] = {0};
                int most = 0;
                int deletions = 0;

                // Try to keep s[i..j]
                for (int j = i; j < n; j++) {
                    cnt[s[j] - 'a']++;
                    most = max(most, cnt[s[j] - 'a']);
                    deletions = (j - i + 1) - most;

                    if (del + deletions > k) continue;

                    int len = 1;  // one char
                    if (most > 1) len += to_string(most).size();

                    dp[i][del] = min(dp[i][del], len + dp[j+1][del + deletions]);
                }

                // Option: delete current char
                if (del + 1 <= k) {
                    dp[i][del] = min(dp[i][del], dp[i+1][del+1]);
                }
            }
        }

        return dp[0][0];
    }
};
