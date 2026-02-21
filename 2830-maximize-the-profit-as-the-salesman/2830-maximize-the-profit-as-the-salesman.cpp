class Solution {
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end(), cmp);

        int m = offers.size();
        vector<int> dp(m);

        dp[0] = offers[0][2];

        for(int i = 1; i < m; i++){
            int profit = offers[i][2];

            // binary search for last non-overlapping
            int l = 0, r = i - 1;
            int j = -1;

            while(l <= r){
                int mid = (l + r) / 2;
                if(offers[mid][1] < offers[i][0]){
                    j = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if(j != -1)
                profit += dp[j];

            dp[i] = max(dp[i-1], profit);
        }

        return dp[m-1];
    }
};