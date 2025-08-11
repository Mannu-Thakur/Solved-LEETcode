//  
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        map<pair<int,int>, int> cache;

        function<int(int,int)> dfs = [&](int r, int c) -> int {
            if (r == ROWS || c == COLS || matrix[r][c] == 0)
                return 0;
            if (cache.count({r, c}))
                return cache[{r, c}];
            
            return cache[{r, c}] = 1 + min({
                dfs(r + 1, c),
                dfs(r, c + 1),
                dfs(r + 1, c + 1)
            });
        };

        int res = 0;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                res += dfs(r, c);
            }
        }
        return res;
    }
};
