class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1, 1);  // Initialize row with 1s
            
            // Fill the internal elements of the row
            for (int j = 1; j < i; ++j) {
                row[j] = res[i - 1][j - 1] + res[i - 1][j];
            }

            res.push_back(row);
        }

        return res;
    }
};
