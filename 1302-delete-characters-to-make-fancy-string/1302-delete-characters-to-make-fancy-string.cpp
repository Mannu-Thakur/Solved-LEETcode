class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            int len = ans.length();
            // if last two characters are same as current, skip
            if (len >= 2 && ans[len - 1] == s[i] && ans[len - 2] == s[i]) continue;
            ans += s[i];
        }
        
        return ans;
    }
};
