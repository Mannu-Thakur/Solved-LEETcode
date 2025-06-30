class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int cnt = INT_MIN;

        unordered_map<int, int>mpp;
        for(auto &f : edges){
            int a = f[0];
            int b = f[1];
            mpp[a]++;
            mpp[b]++;
        }
        int num = 0;

        for(auto &x: mpp){
            if(cnt < x.second){
                cnt = x.second;
                num = x.first;
            }
        }

        return num;
    }
};