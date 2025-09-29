class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n = nums.size();
        vector<vector<int>> g(n);
        for (auto &e : swaps) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            // BFS/DFS to collect component
            vector<int> comp;
            stack<int> st;
            st.push(i);
            vis[i] = 1;
            while (!st.empty()) {
                int u = st.top(); st.pop();
                comp.push_back(u);
                for (int v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        st.push(v);
                    }
                }
            }

            // Count evens and odds in this component
            int evens = 0, odds = 0;
            vector<int> vals;
            for (int idx : comp) {
                vals.push_back(nums[idx]);
                if (idx % 2 == 0) evens++;
                else odds++;
            }

            sort(vals.begin(), vals.end(), greater<int>());

            // Assign top `evens` values to +, rest to -
            for (int j = 0; j < (int)vals.size(); j++) {
                if (j < evens) ans += vals[j];
                else ans -= vals[j];
            }
        }
        return ans;
    }
};
