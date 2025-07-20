class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 0;
        
        for (int num : st) {
            // Only start counting if it's the beginning of a sequence
            if (st.find(num - 1) == st.end()) {
                int curr = num;
                int len = 1;
                
                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    len++;
                }
                res = max(res, len);
            }
        }
        return res;
    }
};
