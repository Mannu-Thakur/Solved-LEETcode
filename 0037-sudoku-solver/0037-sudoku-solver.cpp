class Solution {

    bool canNumBePlaced(char num, int rowInd, int colInd, vector<vector<char>>& board) {

        // checking in the row
        for (int j = 0; j < 9; ++j) {
            if (board[rowInd][j] == num)
                return false;
        }

        // chceking in the column
        for (int i = 0; i < 9; ++i) {
            if (board[i][colInd] == num)
                return false;
        }

        int sr = (rowInd / 3) * 3;
        int sc = (colInd / 3) * 3;
        for (int i = sr; i < sr + 3; i++) {
            for (int j = sc; j < sc + 3; j++) {
                if (board[i][j] == num)
                    return false;
            }
        }

        return true;
    }
    bool solve(int rowInd, int colInd, vector<vector<char>>& board) {
        if (rowInd == 9) {
            return true; // we found a valid answer
        }

        if (colInd == 9) {
            return solve(rowInd + 1, 0, board);
        }

        if (board[rowInd][colInd] != '.') {
            return solve(rowInd, colInd + 1, board);
        }

        for (char num = '1'; num <= '9'; num++) {
            if (canNumBePlaced(num, rowInd, colInd, board)) {
                board[rowInd][colInd] = num;
                bool res = solve(rowInd, colInd + 1, board);
                if (res == true) {
                    return true;
                }
            }
        }

        board[rowInd][colInd] = '.';

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) { 
        solve(0, 0, board); 
    }
};