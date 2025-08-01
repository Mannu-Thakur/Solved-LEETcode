class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        vector<string> ans;

        unordered_map<string, multiset<string>> adj;
        for (auto& find : tickets) {
            adj[find[0]].insert(find[1]);
        }

        stack<string> st;
        st.push("JFK");  
        while (!st.empty()) {
            string curr = st.top();
            if (!adj[curr].empty()) {
               
                auto it = adj[curr].begin();
                st.push(*it);
                adj[curr].erase(it);  
            } else {
                
                ans.push_back(curr);
                st.pop();
            }
        }

        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
