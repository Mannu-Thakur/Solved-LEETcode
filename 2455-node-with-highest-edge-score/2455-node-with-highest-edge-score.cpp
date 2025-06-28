class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        unordered_map<int, long long> mp; // node -> score

        for(int i = 0; i < n; ++i) {
            mp[edges[i]] += i;
        } 

        long long maxi = 0;
        int ans = n; // initialize to maximum possible value
        for(auto &entry : mp) {
            if(entry.second > maxi || (entry.second == maxi && entry.first < ans)) {
                maxi = entry.second;
                ans = entry.first;
            }
        }

        return ans;
    }
};
