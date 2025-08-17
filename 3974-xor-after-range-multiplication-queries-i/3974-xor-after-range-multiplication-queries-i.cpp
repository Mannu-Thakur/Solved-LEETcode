 

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        int q = queries.size();

        for(int i = 0; i < q; ++i) {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];

            for(int ind = l; ind <= r; ind += k) {
                nums[ind] = (1LL * nums[ind] * v) % MOD;
            }
        }

        int bits = 0;
        for(auto &f : nums) {
            bits ^= f;
        }

        return bits;
    }
};
