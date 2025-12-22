class Solution {
public:
    vector<vector<int>> adj;
    vector<int> total;
    long long ans = 0;

    vector<int> dfs(int u, int parent, vector<int>& group) {
         vector<int> cnt(21, 0);

         cnt[group[u]] = 1;

        for (int v : adj[u]) {
            if (v == parent) continue;

            vector<int> child = dfs(v, u, group);

             for (int g = 1; g <= 20; g++) {
                ans += 1LL * child[g] * (total[g] - child[g]);
                cnt[g] += child[g];
            }
        }
        return cnt;
    }

    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        adj.resize(n);
        total.assign(21, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for (int g : group) total[g]++;

        dfs(0, -1, group);
        return ans;
    }
};
