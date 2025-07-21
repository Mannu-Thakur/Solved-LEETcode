 

class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;  // empty string = 0 partitions

        for (int i = 1; i <= n; ++i) {
            unordered_map<char, int> freq;
            for (int j = i; j >= 1; --j) {
                freq[s[j - 1]]++;
                int minFreq = INT_MAX, maxFreq = INT_MIN;
                for (auto &[ch, f] : freq) {
                    minFreq = min(minFreq, f);
                    maxFreq = max(maxFreq, f);
                }
                if (minFreq == maxFreq) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }

        return dp[n];
    }
};
