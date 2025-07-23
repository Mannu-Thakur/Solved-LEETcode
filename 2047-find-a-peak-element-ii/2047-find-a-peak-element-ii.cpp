class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int maxCol = 0;

            for (int j = 1; j < m; ++j) {
                if (mat[mid][j] > mat[mid][maxCol]) {
                    maxCol = j;
                }
            }

            int up = mid - 1 >= 0 ? mat[mid - 1][maxCol] : -1;
            int down = mid + 1 < n ? mat[mid + 1][maxCol] : -1;

            if (mat[mid][maxCol] > up && mat[mid][maxCol] > down) {
                return {mid, maxCol};  // ✅ returning a single peak as vector<int>
            } else if (down > mat[mid][maxCol]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return {-1, -1};  // shouldn't happen in valid inputs
    }
};
