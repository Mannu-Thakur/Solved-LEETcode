class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.length();
        int x = 0, y = 0;

        set<pair<int,int>> st;

        // First window
        for (int i = 0; i < k; ++i) {
            if (s[i] == 'U') {
                y++;
            }
            if (s[i] == 'R') {
                x++;
            }
            if (s[i] == 'D') {
                y--;
            }
            if (s[i] == 'L') {
                x--;
            }
        }
        st.insert({x, y});

        // Sliding window
        for (int i = 0; i < n - k; ++i) {
            // Remove outgoing char
            if (s[i] == 'U') {
                y--;
            }
            if (s[i] == 'R') {
                x--;
            }
            if (s[i] == 'D') {
                y++;
            }
            if (s[i] == 'L') {
                x++;
            }

            // Add incoming char
            if (s[i + k] == 'U') {
                y++;
            }
            if (s[i + k] == 'R') {
                x++;
            }
            if (s[i + k] == 'D') {
                y--;
            }
            if (s[i + k] == 'L') {
                x--;
            }

            st.insert({x, y});
        }

        return st.size();
    }
};
