class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for (auto &word : words) {
            int sum = 0;

            for (char c : word) {
                int idx = c - 'a';   // alphabet index
                sum += weights[idx];
            }

            sum %= 26;

            ans += char('a' + (25 - sum));  // reverse mapping
        }

        return ans;
    }
};
