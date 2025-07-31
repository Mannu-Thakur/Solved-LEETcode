class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        int n = chars.size();

        int cnt = 1;
        char last = chars[0];

        for (int i = 1; i < n; ++i) {
            if (chars[i] == last) {
                cnt++;
            } else {
                s.push_back(last);
                if (cnt > 1) {
                    string cntStr = to_string(cnt);
                    s += cntStr; // add all digits of count
                }
                cnt = 1; // reset for new char
                last = chars[i];
            }
        }

        // Handle last group
        s.push_back(last);
        if (cnt > 1) {
            string cntStr = to_string(cnt);
            s += cntStr;
        }

        // Write back to chars
        for (int i = 0; i < s.size(); ++i)
            chars[i] = s[i];

        return s.size();
    }
};
