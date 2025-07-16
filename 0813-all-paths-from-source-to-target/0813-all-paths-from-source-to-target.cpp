// class Solution {
//     int solve(int start, vector<bool>&vis, vector<vector<int>>&adj, vector<vector<int>>&graph, int n){
//         int cnt = 0;

//         if(start == n-1) return 1;
//         vis[start] = true;

//         for(auto &nbr: adj[start]){
//             if(!vis[nbr]){
//               cnt +=  solve(nbr, vis, adj, graph, n);
//             }
//         }

//         return cnt;
//     }
// public:
//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//         vector<vector<int>>res;
//         int n = graph.size();
//         int m = graph[0].size();

//         vector<vector<int>>adj(n);
//         for(int i=0; i<n; ++i){
//            for(auto &f: graph[i]){
//                 adj[i].push_back(f);
//            }
//         }


//         vector<bool>vis(n, false);
//        return solve(0, vis, adj, graph, n);
//     }
// };




class Solution {
    void solve(int start, vector<int>& path, vector<vector<int>>& res, vector<vector<int>>& graph, int n) {
        path.push_back(start);

        if (start == n - 1) {
            res.push_back(path);  // found one complete path
        }
        
        for (auto &nbr : graph[start]) {
          solve(nbr, path, res, graph, n);
         }


        path.pop_back();  // backtrack
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> path;
        solve(0, path, res, graph, n);
        return res;
    }
};
