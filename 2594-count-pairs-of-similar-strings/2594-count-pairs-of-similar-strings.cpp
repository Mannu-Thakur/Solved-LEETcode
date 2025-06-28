class Solution {
    bool isSimilar(const string &a, const string &b) {
        unordered_set<char> sa(a.begin(), a.end());
        unordered_set<char> sb(b.begin(), b.end());
        return sa == sb;
    }

public:
    int similarPairs(vector<string>& words) {
        int cnt = 0;
        int n = words.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isSimilar(words[i], words[j])) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
