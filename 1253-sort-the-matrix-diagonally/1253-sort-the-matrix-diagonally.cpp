class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        unordered_map<int, vector<int>> mp;
        
        // Collect diagonals
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                mp[i - j].push_back(mat[i][j]);
            }
        }
        
        // Sort each diagonal
        for(auto &f : mp){
            sort(f.second.rbegin(), f.second.rend());  
        }
        
         for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                mat[i][j] = mp[i - j].back();
                mp[i - j].pop_back();
            }
        }
        
        return mat;
    }
};
