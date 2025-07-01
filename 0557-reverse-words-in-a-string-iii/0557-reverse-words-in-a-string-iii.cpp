class Solution {
    void solve(string &s) {
        int n = s.length();
        for (int i = 0; i < n / 2; ++i) {
            swap(s[i], s[n - i - 1]);
        }
    }

public:
    string reverseWords(string s) {
        int n = s.length();
        string temp = "", ans = "";

        for (int i = 0; i < n; ++i) {
            if (s[i] != ' ') {
                temp += s[i];
            } else {
                solve(temp);
                ans += temp + " ";
                temp = "";
            }
        }

        // handle the last word (no space after it)
        if (!temp.empty()) {
            solve(temp);
            ans += temp;
        }

        return ans;
    }
};
