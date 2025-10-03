class Solution {
    #define p pair<int, pair<int, int>> // {value, {x, y}}
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        int water = 0;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        priority_queue<p, vector<p>, greater<p>> pq;

        // Add all boundary cells to the priority queue
        for (int i = 0; i < n; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][m - 1], {i, m - 1}});
            visited[i][0] = visited[i][m - 1] = true;
        }
        for (int j = 0; j < m; j++) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[n - 1][j], {n - 1, j}});
            visited[0][j] = visited[n - 1][j] = true;
        }

        int dx[4] = {0, 0, -1, 1}; // Horizontal movements
        int dy[4] = {-1, 1, 0, 0}; // Vertical movements

        while (!pq.empty()) {
            auto top = pq.top(); 
            pq.pop();
            int r = top.second.first;
            int c = top.second.second;
            int curhgt = top.first;

            for (int d = 0; d < 4; d++) {
                int xx = r + dx[d];
                int yy = c + dy[d];

                if (xx >= 0 && yy >= 0 && xx < n && yy < m && !visited[xx][yy]) {
                    water += max(0, curhgt - heightMap[xx][yy]);
                    pq.push({max(heightMap[xx][yy], curhgt), {xx, yy}});
                    visited[xx][yy] = true;
                }
            }
        }
        return water;
    }
};
