#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int N;

    bool invalid(int r, int c) {
        return r < 0 || c < 0 || r >= N || c >= N;
    }

    void dfs(int r, int c, vector<vector<int>>& grid, set<pair<int, int>>& visit) {
        if (invalid(r, c) || grid[r][c] == 0 || visit.count({r, c})) return;
        
        visit.insert({r, c});
        
        for (int i = 0; i < 4; ++i) {
            dfs(r + dx[i], c + dy[i], grid, visit);
        }
    }

    int bfs(vector<vector<int>>& grid, set<pair<int, int>>& visit) {
        queue<pair<int, int>> q;
        for (auto& cell : visit) q.push(cell);

        int res = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto [r, c] = q.front(); q.pop();
                for (int d = 0; d < 4; ++d) {
                    int nr = r + dx[d];
                    int nc = c + dy[d];

                    if (invalid(nr, nc) || visit.count({nr, nc})) continue;

                    if (grid[nr][nc] == 1) return res;

                    visit.insert({nr, nc});
                    q.push({nr, nc});
                }
            }
            res++;
        }
        return res;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        N = grid.size();
        set<pair<int, int>> visit;

        bool found = false;
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                if (grid[r][c] == 1) {
                    dfs(r, c, grid, visit);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        return bfs(grid, visit);
    }
};
