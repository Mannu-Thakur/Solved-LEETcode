class Solution {
    void dfs(int &ans , int src, vector<int>&visited, vector<vector<int>>&forward, vector<vector<int>>&backward, int n, vector<vector<int>>&connections){
       visited[src]=1;
       for(auto &find: forward[src]){
        if(!visited[find]){
            ans++;
            dfs(ans, find, visited, forward, backward, n, connections);
        }
       }


       for(auto &findd: backward[src]){
        if(!visited[findd]){
            dfs(ans, findd, visited, forward, backward, n, connections);
        }
       }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> forward(n), backward(n);
        for(int i=0; i<connections.size(); ++i){
            int a = connections[i][0];
            int b = connections[i][1];

            forward[a].push_back(b);
            backward[b].push_back(a);
        }
        vector<int>visited(n);
        int ans = 0;
        dfs(ans, 0, visited, forward, backward,n,connections);
        return ans;
    }
};