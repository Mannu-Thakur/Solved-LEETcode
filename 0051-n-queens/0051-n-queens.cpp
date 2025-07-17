class Solution {
    bool check(int rowInd, int colInd, vector<string>& temp, int n) {
    
        for (int i = 0; i < colInd; ++i) {
            if (temp[rowInd][i] == 'Q') return false;
        }

 
        for (int i = rowInd, j = colInd; i >= 0 && j >= 0; --i, --j) {
            if (temp[i][j] == 'Q') return false;
        }

        
        for (int i = rowInd, j = colInd; i < n && j >= 0; ++i, --j) {
            if (temp[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(int colInd, int n, vector<string>&temp, vector<vector<string>>& ans) {
        if (colInd == n) {
            ans.push_back(temp);  
            return;
        }

        for (int rowInd = 0; rowInd < n; ++rowInd) {
            if (check(rowInd, colInd, temp, n)) {
                temp[rowInd][colInd] = 'Q';  
                solve(colInd + 1, n, temp, ans);
                temp[rowInd][colInd] = '.';  
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp(n, string(n, '.'));  
        solve(0, n, temp, ans);
        return ans;
    }
};
