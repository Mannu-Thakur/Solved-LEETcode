class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ht(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    ht[i][j] = 0;
                }
            }
        }

        // Perform BFS
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            int x = f.first, y = f.second;

            for (int i = 0; i < 4; ++i) {
                int xx = x + dx[i];
                int yy = y + dy[i];

                if (xx >= 0 && xx < n && yy >= 0 && yy < m && ht[xx][yy] == -1) {
                    ht[xx][yy] = ht[x][y] + 1;
                    q.push({xx, yy});
                }
            }
        }

        return ht;
    }
};
