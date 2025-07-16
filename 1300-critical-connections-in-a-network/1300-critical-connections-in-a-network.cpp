class Solution {
private:
    int timer = 1;

    void dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj, int tin[], int low[], vector<vector<int>>& res) {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        
        for (auto &nbr : adj[node]) {
            if (nbr == parent) continue;

            if (!vis[nbr]) {
                dfs(nbr, node, vis, adj, tin, low, res);
                low[node] = min(low[node], low[nbr]);

                if (low[nbr] > tin[node]) {
                    res.push_back({node, nbr});  // It's a bridge
                }
            } else {
                low[node] = min(low[node], tin[nbr]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto &edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n, 0);
        vector<vector<int>> res;
        int tin[n], low[n];

        dfs(0, -1, vis, adj, tin, low, res);
        return res;
    }
};
