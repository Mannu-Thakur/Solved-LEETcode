class Solution {
    string reverse(string &s) {
        int n = s.length();
        for (int i = 0; i < n / 2; ++i) {
            swap(s[i], s[n - i - 1]);
        }
        return s;
    }

public:
    string finalString(string s) {
        string res = "";

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'i') {
                reverse(res);   
            } else {
                res += s[i];   // append otherwise
            }
        }

        return res;
    }
};
