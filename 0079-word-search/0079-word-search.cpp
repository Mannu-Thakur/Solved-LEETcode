class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool solve(vector<vector<int>>& vis, vector<vector<char>>& board, string word, int n, int m, int i, int j, int idx) {
        if (idx == word.size()) {
            return true;
        }

        if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] == 1 || board[i][j] != word[idx]) {
            return false;
        }

        vis[i][j] = 1;  

        for (int d = 0; d < 4; ++d) {
            int new_x = i + dx[d];
            int new_y = j + dy[d];
            if (solve(vis, board, word, n, m, new_x, new_y, idx + 1)) {
                return true;
            }
        }

        vis[i][j] = 0; 
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));  

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0] && solve(vis, board, word, n, m, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
