class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        unordered_map<string, int> outdegree;

        // Count outdegree for each city
        for (auto &f : paths) {
            string from = f[0];
            string to = f[1];
            outdegree[from]++;
            // We don't increment for 'to' city — it may be a destination
            if (outdegree.find(to) == outdegree.end()) {
                outdegree[to] = 0;
            }
        }

        // Find the city with 0 outdegree
        for (auto &entry : outdegree) {
            if (entry.second == 0) {
                return entry.first;
            }
        }

        return "";
    }
};
