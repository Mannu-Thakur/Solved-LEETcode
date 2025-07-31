class Solution {
    string solve(string s) {
        int n = s.length();
        int read = 0;
        string result = "";

        while (read < n) {
            int cnt = 0;
            char curr = s[read];

            while (read < n && s[read] == curr) {
                read++;
                cnt++;
            }

            result += to_string(cnt);
            result += curr;
        }

        return result;
    }

public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string prev = countAndSay(n - 1);
        return solve(prev);
    }
};
