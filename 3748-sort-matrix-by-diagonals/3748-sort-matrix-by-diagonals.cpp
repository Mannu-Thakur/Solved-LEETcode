class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        unordered_map<int, vector<int>> mpp;

        // Step 1: Store all diagonals using (i - j) as the key
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mpp[i - j].push_back(grid[i][j]);
            }
        }

        // Step 2: Sort each diagonal
        for (auto& [key, val] : mpp) {
            if (key >= 0) {
                sort(val.begin(), val.end(), greater<int>());  
            } else {
                sort(val.begin(), val.end());  
            }
        }

        // Step 3: Refill the matrix with sorted diagonals
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                grid[i][j] = mpp[i - j].front();
                mpp[i - j].erase(mpp[i - j].begin());
            }
        }

        return grid;
    }
};
