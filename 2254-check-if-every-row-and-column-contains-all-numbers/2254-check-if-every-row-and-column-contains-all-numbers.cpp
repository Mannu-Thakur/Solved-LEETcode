class Solution {
    bool valid(vector<vector<int>>& matrix, int row, int col, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        // check column
        for (int k = 0; k < n; ++k) {
            if (k != row && matrix[k][col] == target) 
                return false;
        }

        // check row
        for (int k = 0; k < m; ++k) {
            if (k != col && matrix[row][k] == target) 
                return false;
        }

        return true;
    }
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int temp = matrix[i][j];
                if (temp == 0) return false;  
                if (!valid(matrix, i, j, temp)) {
                    return false;
                }
            }
        }

        return true;
    }
};
