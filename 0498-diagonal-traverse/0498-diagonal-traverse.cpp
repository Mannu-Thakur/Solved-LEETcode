class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int n = mat.size(), m = mat[0].size();

        map<int, vector<int>> mp;  // use map to maintain sorted keys

        // Group elements by sum of indices (i + j)
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                mp[i + j].push_back(mat[i][j]);
            }
        }

        bool flip = true;
        for(auto &it : mp){
            if(flip) reverse(it.second.begin(), it.second.end());
            for(int num : it.second) res.push_back(num);
            flip = !flip;
        }

        return res;
    }
};
