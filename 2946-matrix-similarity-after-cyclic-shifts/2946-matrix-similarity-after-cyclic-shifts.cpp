class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> original = mat;

        k = k % m;  

        while(k--){
            vector<vector<int>> temp = mat;

            for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j){
                    if(i % 2 == 0){
                        temp[i][( j - 1 + m ) % m] = mat[i][j];
                    } else {
                        temp[i][j] = mat[i][(j - 1 + m) % m];
                    }
                }
            }

            mat = temp;
        }

        return mat == original;
    }
};