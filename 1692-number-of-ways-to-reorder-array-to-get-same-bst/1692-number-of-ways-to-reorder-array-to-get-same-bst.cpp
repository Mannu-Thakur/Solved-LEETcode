class Solution {
    typedef long long ll;
    ll mod = 1e9 + 7;
    vector<vector<ll>> pascal;

public:
    void buildPascal(int n) {
        pascal.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            pascal[i].resize(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % mod;
            }
        }
    }

    ll dfs(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        vector<int> left, right;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        ll leftWays = dfs(left);
        ll rightWays = dfs(right);

        // Combine left and right
        ll totalWays = pascal[n - 1][left.size()];
        return (((leftWays * rightWays) % mod) * totalWays) % mod;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        buildPascal(n);
        ll res = dfs(nums);
        return (res - 1 + mod) % mod;  
    }
};
