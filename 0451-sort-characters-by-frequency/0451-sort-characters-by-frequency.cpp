class Solution {
public:
    string frequencySort(string s) {
        vector<int> f(128, 0);  // ASCII range (0–127 is safe for standard characters)

        for (char c : s) {
            f[(int)c]++;
        }

        vector<pair<int, char>> fr;
        for (int i = 0; i < 128; ++i) {
            if (f[i] > 0) {
                fr.push_back({f[i], (char)i});
            }
        }

        sort(fr.rbegin(), fr.rend());  // Sort by frequency descending

        string res = "";
        for (auto &p : fr) {
            res += string(p.first, p.second);
        }

        return res;
    }
};
