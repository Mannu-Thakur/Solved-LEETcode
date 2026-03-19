class Solution {
    int solve(vector<int>& temp, int target){
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0, cnt = 0;

        for(int x : temp){
            sum += x;

            if(mp.find(sum - target) != mp.end()){
                cnt += mp[sum - target];
            }

            mp[sum]++;
        }

        return cnt;
    }

public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;

        for(int top = 0; top < n; top++){
            vector<int> temp(m, 0);

            for(int bottom = top; bottom < n; bottom++){
                
                for(int col = 0; col < m; col++){
                    temp[col] += matrix[bottom][col];
                }

                ans += solve(temp, target);
            }
        }

        return ans;
    }
};