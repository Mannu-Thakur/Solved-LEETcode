class Solution {
public:
    // BFS to compute distance from a source node
    vector<int> bfs(int src, vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    }

    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        // Build adjacency list
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Distances from x, y, z
        vector<int> dx = bfs(x, adj);
        vector<int> dy = bfs(y, adj);
        vector<int> dz = bfs(z, adj);

        int count = 0;

        // Check each node
        for (int i = 0; i < n; i++) {
            vector<int> d = {dx[i], dy[i], dz[i]};
            sort(d.begin(), d.end());

            long long a = d[0], b = d[1], c = d[2];
            if (a * a + b * b == c * c) {
                count++;
            }
        }

        return count;
    }
};
