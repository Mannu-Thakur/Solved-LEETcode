class Solution {
    typedef long long ll;
public:
    long long appealSum(string s) {
        int n = s.size();
        vector<int> last(26, -1);
        ll res = 0;

        for(int i = 0; i < n; ++i) {
            int ch = s[i] - 'a';
            res += (ll)(i - last[ch]) * (n - i);
            last[ch] = i;
        }

        return res;
    }
};
