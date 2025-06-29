class Solution {
public:
    static bool cmp(const tuple<int,int,int>& a, const tuple<int,int,int>& b) {
        return get<1>(a) < get<1>(b); // sort by endTime
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int, int, int>> jobs;
        for (int i = 0; i < n; ++i)
            jobs.push_back({startTime[i], endTime[i], profit[i]});

        sort(jobs.begin(), jobs.end(), cmp);

        // dp[i]: max profit till i-th job
        vector<int> dp(n);
        dp[0] = get<2>(jobs[0]);

        for (int i = 1; i < n; ++i) {
            int currProfit = get<2>(jobs[i]);
            int lo = 0, hi = i - 1, idx = -1;

            // Binary search to find the last job that ends <= current job's start
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (get<1>(jobs[mid]) <= get<0>(jobs[i])) {
                    idx = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            if (idx != -1) currProfit += dp[idx];
            dp[i] = max(dp[i - 1], currProfit);
        }

        return dp[n - 1];
    }
};
