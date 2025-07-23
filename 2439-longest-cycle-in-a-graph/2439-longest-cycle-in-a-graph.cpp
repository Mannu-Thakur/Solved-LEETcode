class Solution {
    int length = -1;

    int dfs(int node, vector<int>& visited, vector<int>& currPath, int cl, vector<int>& edges) {
        visited[node] = 1;
        currPath[node] = cl;

        int nbr = edges[node];

        if (nbr != -1) {
            if (!visited[nbr]) {
                dfs(nbr, visited, currPath, cl + 1, edges);
            } else if (currPath[nbr] != 0) {
                int cycleLength = currPath[node] - currPath[nbr] + 1;
                length = max(cycleLength, length);
            }
        }

        currPath[node] = 0;
        return length;
    }

public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, 0);
        vector<int> currPath(n, 0);
        int cl = 1;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, visited, currPath, cl, edges);
            }
        }

        return length;
    }
};
