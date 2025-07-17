class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        int ans = 0;
        queue<int>q;
        unordered_map<int, vector<int>>graph(n);
        vector<vector<int>>cnt(n, vector<int>(26));
        vector<int>indegree(n,0);

 for (int i = 0; i < edges.size(); ++i) {
    int u = edges[i][0];
    int v = edges[i][1];
    graph[u].push_back(v);
    indegree[v]++;
}


        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int num = 0;
        while(!q.empty()){
            int f = q.front();
            q.pop();

            num++;
            cnt[f][colors[f] - 'a']++;
            ans = max(ans, cnt[f][colors[f] - 'a']);

            for(auto nbr: graph[f]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }


                for(int j=0; j<26; ++j){
                    cnt[nbr][j] = max(cnt[nbr][j], cnt[f][j]);
                }
            }
        }

        return num == n ? ans : -1;



    }
};