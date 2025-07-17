class Solution {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        queue<pair<pair<int,int>, int>> q;  // {{x,y}, steps}
        int r = entrance[0], c = entrance[1];
        
        q.push({{r, c}, 0});
        maze[r][c] = '+';  // mark visited

        while (!q.empty()) {
            auto [pos, steps] = q.front();
            q.pop();
            int x = pos.first, y = pos.second;

            // Check if it's an exit (boundary but not entrance)
            if ((x == 0 || y == 0 || x == n - 1 || y == m - 1) && (x != r || y != c))
                return steps;

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && maze[nx][ny] == '.') {
                    maze[nx][ny] = '+';  // mark visited
                    q.push({{nx, ny}, steps + 1});
                }
            }
        }

        return -1;  // no exit reachable
    }
};
