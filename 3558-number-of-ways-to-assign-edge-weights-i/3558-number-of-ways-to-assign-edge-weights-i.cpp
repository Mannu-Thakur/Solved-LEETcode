 

class Solution {
  void solve(int node, int parent, int depth, int &maxDepth, vector<vector<int>> &graph) {
    maxDepth = max(maxDepth, depth);
    for (auto &neighbour : graph[node]) {
        if (neighbour != parent)
            solve(neighbour, node, depth + 1, maxDepth, graph);
    }
}


public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int mod  =  1e9+7;
        int n = edges.size() + 1;   
        vector<vector<int>> adj(n + 1);   

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(n + 1, false);   
        int ht = 0;
        solve(1, -1, 0, ht, adj);      

        int res = 1;
        for(int i=1; i<ht; ++i){
            res = (res * 2) % mod;
        }
        return res;
    }
};
