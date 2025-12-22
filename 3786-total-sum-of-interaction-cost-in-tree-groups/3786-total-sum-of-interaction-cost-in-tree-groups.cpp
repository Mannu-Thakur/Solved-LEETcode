class Solution {
public:
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // total[g] = total nodes having group g
        vector<int> total(21, 0);
        for (int g : group) total[g]++;

        long long ans = 0;

        function<vector<int>(int, int)> dfs = [&](int u, int parent) {
            vector<int> cnt(21, 0);
            cnt[group[u]] = 1;

            for (int v : adj[u]) {
                if (v == parent) continue;

                vector<int> child = dfs(v, u);

                // edge (u - v) contribution
                for (int g = 1; g <= 20; g++) {
                    ans += 1LL * child[g] * (total[g] - child[g]);
                    cnt[g] += child[g];
                }
            }
            return cnt;
        };

        dfs(0, -1);
        return ans;
    }
};
