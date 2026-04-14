class Solution {
public:
    vector<int> robot;
    vector<vector<int>> factory;
    int n, m;
    vector<vector<long long>> dp;

    long long solve(int i, int j) {
        if (i == n) return 0;                 
        if (j == m) return 1e15;               

        if (dp[i][j] != -1) return dp[i][j];

        // Option 1: skip this factory
        long long ans = solve(i, j + 1);

        // Option 2: assign k robots to this factory
        long long cost = 0;
        for (int k = 1; k <= factory[j][1]; k++) {
            if (i + k > n) break;

            cost += abs(robot[i + k - 1] - factory[j][0]);
            ans = min(ans, cost + solve(i + k, j + 1));
        }

        return dp[i][j] = ans;
    }

    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& f) {
        robot = r;
        factory = f;

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        n = robot.size();
        m = factory.size();

        dp.assign(n, vector<long long>(m, -1));

        return solve(0, 0);
    }
};