class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    void dfs(vector<vector<char>>& grid, int r, int c, int x, int y){
        grid[x][y] = '0';

        for(int i=0; i<4; ++i){
            int dxx = x + dx[i];
            int dyy = y + dy[i];

           if (dxx >= 0 && dxx < r && dyy >= 0 && dyy < c && grid[dxx][dyy] == '1'){
                dfs(grid, r,c,dxx, dyy);
            }
        }
    }


    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if( n == 0) return 0;
        
        int cols = grid[0].size();
        int islands  = 0;

      for(int i=0; i<n; ++i){
        for(int j = 0; j<cols; ++j){
            if(grid[i][j] == '1'){
                islands++;
                dfs(grid, n, cols,i,j);
            }
        }
      } 
       return islands;
    }
   
};