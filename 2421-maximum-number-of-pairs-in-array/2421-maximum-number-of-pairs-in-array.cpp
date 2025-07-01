class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto &f : nums) {
            mp[f]++;
        }

        int cnt = 0;   // number of pairs
        int left = 0;  // unpaired elements

        for (auto &f : mp) {
            cnt += f.second / 2;
            left += f.second % 2;
        }

        return {cnt, left};
    }
};
