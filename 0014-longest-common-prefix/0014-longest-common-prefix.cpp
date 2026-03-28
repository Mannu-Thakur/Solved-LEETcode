class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        int n = strs.size();
        int sz = strs[0].length();

        for (int i = 1; i < n; ++i) {
            sz = min(sz, (int)strs[i].length());
        }

        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < n; ++j) {
                if (strs[0][i] != strs[j][i]) {
                    return ans;
                }
            }
            ans += strs[0][i];
        }
        return ans;
    }
};