#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Build adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        auto dijkstra = [&](int src) {
            vector<int> dist(n, INT_MAX);
            dist[src] = 0;
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
            pq.push({0, src});

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                if (d > dist[u]) continue;

                for (auto &[v, w] : adj[u]) {
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }

            int reachable = 0;
            for (int i = 0; i < n; i++) {
                if (i != src && dist[i] <= distanceThreshold)
                    reachable++;
            }
            return reachable;
        };

        int minReachable = n + 1, result = -1;

        // Run Dijkstra from every node
        for (int i = 0; i < n; i++) {
            int reachable = dijkstra(i);
            if (reachable <= minReachable) {
                minReachable = reachable;
                result = i;  // prefer larger index in case of tie
            }
        }

        return result;
    }
};
