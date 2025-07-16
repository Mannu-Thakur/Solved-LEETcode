class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1, 0), outdegree(n+1, 0);
        
        for(auto &t : trust){
            int a = t[0], b = t[1];
            outdegree[a]++;   // trusts someone
            indegree[b]++;    // trusted by someone
        }
        
        for(int i=1; i<=n; ++i){
            if(outdegree[i]==0 && indegree[i]==n-1) return i;
        }
        return -1;
    }
};
