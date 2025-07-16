class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color, int col) {
        color[node] = col;
        for (auto &nbr : graph[node]) {
            if (color[nbr] == -1) {
                if (!dfs(nbr, graph, color, !col)) return false;
            } else if (color[nbr] == color[node]) {
                return false; // Conflict detected
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; ++i) {
            if (color[i] == -1 && !dfs(i, graph, color, 0)) {
                return false;
            }
        }
        return true;
    }
};
