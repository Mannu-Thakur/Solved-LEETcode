class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i = y; i<y+k; ++i){
            for(int a = x,  b = x + k -1; a < b ; a++, b--){
                swap(grid[a][i], grid[b][i]);
            }
        }  
        return grid;
    }
};