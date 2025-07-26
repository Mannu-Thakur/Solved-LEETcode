class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (i == j || j == k || k == i) continue;

                    int a = nums[i], b = nums[j], c = nums[k];

                    // 3-digit number with no leading zero, and is even
                    if (a != 0 && c % 2 == 0) {
                        int num = a * 100 + b * 10 + c;
                        st.insert(num);
                    }
                }
            }
        }

        vector<int> ans(st.begin(), st.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};
