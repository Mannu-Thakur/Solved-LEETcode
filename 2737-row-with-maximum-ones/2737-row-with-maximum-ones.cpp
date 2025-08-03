class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int>res;
        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0;
        int ind = 0;

        for(int i=0; i<n; ++i){
            int temp = 0;
            for(int j = 0;j<m; ++j){
                if(mat[i][j] == 1){
                    temp++;
                }
            }

            if(temp > cnt){
                cnt = temp;
                ind = i;
            }
        }
         res.push_back(ind);
         res.push_back(cnt);
         return res;
    }
};