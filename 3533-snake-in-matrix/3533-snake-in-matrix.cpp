class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int row = 0, col = 0;
        for (const string& cmd : commands) {
            if (cmd == "RIGHT" && col + 1 < n) {
                col++;
            } else if (cmd == "LEFT" && col - 1 >= 0) {
                col--;
            } else if (cmd == "DOWN" && row + 1 < n) {
                row++;
            } else if (cmd == "UP" && row - 1 >= 0) {
                row--;
            }
        }
        return row * n + col;
    }
};
