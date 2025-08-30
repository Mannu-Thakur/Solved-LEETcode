class Solution {
    bool check(char num, int rowInd, int colInd, vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            if (board[rowInd][i] == num) return false; 
        }

        for (int j = 0; j < 9; ++j) {
            if (board[j][colInd] == num) return false; 
        }

        int sr = (rowInd / 3) * 3;
        int sc = (colInd / 3) * 3;
        for (int k = sr; k < sr + 3; ++k) {
            for (int x = sc; x < sc + 3; ++x) {
                if (board[k][x] == num) return false; 
            }
        }

        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;

                char num = board[i][j]; 
                board[i][j] = '.';      

                if (!check(num, i, j, board)) {
                    return false;
                }

                board[i][j] = num; // Restore the value
            }
        }
        return true;
    }
};
