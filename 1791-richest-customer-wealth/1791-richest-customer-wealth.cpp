class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n= accounts.size();
        int m = accounts[0].size();

        int ans = 0;
        for(auto &f: accounts){
            int temp = 0;
            for(auto &k: f){
                temp += k;
            }

            ans = max(ans, temp);
        }
        
        return ans;
    }
};