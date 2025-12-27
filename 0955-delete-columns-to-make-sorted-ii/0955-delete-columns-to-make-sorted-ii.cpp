class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();

        vector<bool> fixed(rows - 1, false); // state
        int cnt = 0;

        for (int c = 0; c < cols; ++c) {
            bool bad = false;

            // step 1: validate column
            for (int r = 0; r < rows - 1; ++r) {
                if (!fixed[r] && strs[r][c] > strs[r + 1][c]) {
                    bad = true;
                    break;
                }
            }

            if (bad) {
                cnt++;       // delete column
                continue;    // do NOT update state
            }

            // step 2: update state
            for (int r = 0; r < rows - 1; ++r) {
                if (!fixed[r] && strs[r][c] < strs[r + 1][c]) {
                    fixed[r] = true;
                }
            }
        }

        return cnt;
    }
};
