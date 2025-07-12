class Solution {
    bool solve(vector<int>& arr, int s, int n, vector<bool>& vis){
        if (s < 0 || s >= n) return false;
        if (arr[s] == 0) return true;
        if (vis[s]) return false;
        
        vis[s] = true;
        
        bool left = solve(arr, s - arr[s], n, vis);
        bool right = solve(arr, s + arr[s], n, vis);
        
        return left || right;
    }
    
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, false);
        
        return solve(arr, start, n, vis);
    }
};
