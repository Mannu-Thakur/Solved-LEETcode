class Solution {
    typedef long long ll;
    const int MOD = 1e9 + 7;

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> mp(n);  // adjacency list

        for (auto &f : roads) {
            int u = f[0], v = f[1], w = f[2];
            mp[u].push_back({v, w});
            mp[v].push_back({u, w});
        }

        vector<ll> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});  // {time_so_far, node}

        while (!pq.empty()) {
            auto [curr_time, u] = pq.top(); pq.pop();

            if (curr_time > dist[u]) continue;

            for (auto &[v, t] : mp[u]) {
                ll new_time = curr_time + t;
                if (new_time < dist[v]) {
                    dist[v] = new_time;
                    ways[v] = ways[u];
                    pq.push({new_time, v});
                } else if (new_time == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
