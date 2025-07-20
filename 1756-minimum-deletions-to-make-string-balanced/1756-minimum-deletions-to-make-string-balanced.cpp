class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> left(n, 0), right(n, 0);

        // Count 'a' on the right
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] + (s[i + 1] == 'a');
        }

        // Count 'b' on the left
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] + (s[i - 1] == 'b');
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, right[i] + left[i]);
        }

        return ans;
    }
};
