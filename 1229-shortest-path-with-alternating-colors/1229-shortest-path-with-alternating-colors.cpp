 

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> red(n), blue(n);
        for (auto &f : redEdges) red[f[0]].push_back(f[1]);
        for (auto &f : blueEdges) blue[f[0]].push_back(f[1]);

        unordered_set<string> visited;
        vector<int> ans(n, -1);
        queue<tuple<int, int, string>> q;  // node, length, previous_edge_color
        q.push({0, 0, ""});
        visited.insert("0|");

        while (!q.empty()) {
            auto [node, len, pre_color] = q.front();
            q.pop();

            if (ans[node] == -1) ans[node] = len;

            if (pre_color != "RED") {
                for (int nbr : red[node]) {
                    string key = to_string(nbr) + "|RED";
                    if (!visited.count(key)) {
                        visited.insert(key);
                        q.push({nbr, len + 1, "RED"});
                    }
                }
            }

            if (pre_color != "BLUE") {
                for (int nbr : blue[node]) {
                    string key = to_string(nbr) + "|BLUE";
                    if (!visited.count(key)) {
                        visited.insert(key);
                        q.push({nbr, len + 1, "BLUE"});
                    }
                }
            }
        }

        return ans;
    }
};
