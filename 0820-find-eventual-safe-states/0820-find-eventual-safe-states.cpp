 
class Solution {
    bool dfs(int node, vector<bool>& visited, vector<bool>& currentPath, vector<bool>& safeNodes, vector<vector<int>>& graph) {
        visited[node] = true;
        currentPath[node] = true;

        for (auto& nbr : graph[node]) {
            if (!visited[nbr]) {
                
                if (dfs(nbr, visited, currentPath, safeNodes, graph)) {
                    return true; 
                }
            } else if (currentPath[nbr]) {
                return true; 
            }
        }

        currentPath[node] = false; 
        safeNodes[node] = true; 
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<bool> currentPath(n, false);
        vector<bool> safeNodes(n, false);

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, visited, currentPath, safeNodes, graph);
            }
        }

        
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (safeNodes[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};
