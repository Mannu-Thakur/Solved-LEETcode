class Solution {
    int solve(vector<vector<pair<int,int>>>& adj, int root, vector<bool>& vis) {
        int cnt = 0;
        vis[root] = true;

        for (auto &[nbr, dir] : adj[root]) {
            if (!vis[nbr]) {
                if (dir == 1) cnt++;  
                cnt += solve(adj, nbr, vis);
            }
        }
        return cnt;
    }
public:
    int minReorder(int n, vector<vector<int>>& cun) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : cun) {
            int a = f[0], b = f[1];
            adj[a].push_back({b, 1});  
            adj[b].push_back({a, 0});  
        }
        
        vector<bool> vis(n, false);
        return solve(adj, 0, vis);
    }
};
