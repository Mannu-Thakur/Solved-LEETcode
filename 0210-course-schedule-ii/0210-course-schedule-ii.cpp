class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(numCourses, 0);

        for (const auto& prereq : prerequisites) {
            int u = prereq[1];
            int v = prereq[0];
            graph[u].push_back(v);
            indegree[v]++;
        }

        // for(int i=0; i < numCourses; ++i){
        //     for(auto &find: graph[i]){
        //         indegree[find]++;
        //     }
        // }

        deque<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push_back(i);
            }
        }

        vector<int> ans;
        int num = 0;

        while (!q.empty()) {
            int course = q.front();
            q.pop_front();
            ans.push_back(course);
            num++;

            for (int neighbor : graph[course]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push_back(neighbor);
                }
            }
        }

        if (num == numCourses) {
            return ans;
        }

        return {};
    }
};
