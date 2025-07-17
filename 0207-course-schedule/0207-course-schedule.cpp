class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int>q;
        vector<int>indegree(numCourses,0);
        bool flag  = false;

        // here making the adjacency list;
        unordered_map<int, vector<int>>graph;
        for(int i=0; i<prerequisites.size(); ++i){
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        graph[u].push_back(v);
        indegree[v]++; 
        }

      

        for(int i=0; i<numCourses; ++i){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    int num = 0;
        while(!q.empty()){
            int f = q.front();
            q.pop();

            num++;
            for(int x : graph[f]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                }
            }
            

        }

            return num == numCourses;
    }
};