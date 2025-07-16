class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        vector<int> res(n, 0);
        long long temp = 0;  // use long long to be safe

        for (int i = 0; i < n; ++i) {
            temp = (temp * 10 + (word[i] - '0')) % m;
            if (temp == 0) res[i] = 1;
        }

        return res;
    }
};
