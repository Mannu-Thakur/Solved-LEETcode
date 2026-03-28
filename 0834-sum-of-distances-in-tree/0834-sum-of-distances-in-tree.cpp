class Solution {
    int root_result = 0;
    vector<int>count;
    int N;

    int dfs(unordered_map<int, vector<int>>&adj, int curr_node, int parent, int depth){
         
         int total_count = 1;
         root_result += depth;

         for(auto &nbr: adj[curr_node]){
            if(parent == nbr) continue;

           total_count += dfs(adj, nbr, curr_node, depth+1);
         }

         count[curr_node] = total_count;

         return total_count;
    }

    void dfs_find(unordered_map<int, vector<int>>&adj, int curr_node, int parent, vector<int>&res){

        for(auto &f: adj[curr_node]){
            if(f == parent){
                continue;
            }

            res[f] = res[curr_node] - (count[f]) + (N - count[f]);
            dfs_find(adj, f, curr_node, res);
        }

    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;

        unordered_map<int, vector<int>>adj;

        for(auto&e: edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        root_result = 0;
        count.resize(n);

        dfs(adj, 0, -1, 0);

        vector<int>result(n, 0);
        result[0] = root_result;

        dfs_find(adj, 0, -1, result);  // adj, curr_node, parent, result;
        return result;
    }
};