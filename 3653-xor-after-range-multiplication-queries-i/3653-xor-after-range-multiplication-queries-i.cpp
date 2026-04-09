class Solution {
    const int MOD = 1e9+7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

       for(auto &f : queries){
            int l = f[0];
            int r = f[1];
            int k = f[2];
            int v = f[3];


            for(int i=l; i<=r; i += k){
                nums[i] = (1LL * nums[i] * v) % MOD;
            }
        }


        int ans = 0;
        for(auto &f: nums){
            ans ^= f;
        }

        return ans;
    }
};