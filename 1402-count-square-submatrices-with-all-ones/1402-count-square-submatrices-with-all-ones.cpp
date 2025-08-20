 
class Solution {
public:
    int ROWS, COLS;
    vector<vector<int>> matrix;
    vector<vector<int>> cache;  

    int dfs(int r, int c) {
         if (r == ROWS || c == COLS || matrix[r][c] == 0)
            return 0;

         if (cache[r][c] != -1)
            return cache[r][c];

         int right = dfs(r, c + 1);
        int down = dfs(r + 1, c);
        int diag = dfs(r + 1, c + 1);

        cache[r][c] = 1 + min({right, down, diag});
        return cache[r][c];
    }

    int countSquares(vector<vector<int>>& mat) {
        matrix = mat;
        ROWS = matrix.size();
        COLS = matrix[0].size();
        cache.assign(ROWS, vector<int>(COLS, -1));

        int res = 0;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                res += dfs(r, c);
            }
        }
        return res;
    }
};
