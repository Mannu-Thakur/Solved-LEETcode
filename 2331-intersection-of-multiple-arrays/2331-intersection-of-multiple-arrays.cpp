class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int>res;
        int n = nums.size();

        unordered_map<int, int>mp;
        for(int i=0; i<n; ++i){
            for(int j = 0; j<nums[i].size(); ++j){
                mp[nums[i][j]]++;
            }
        }

        for(auto &f: mp){
            if(f.second == n){
                res.push_back(f.first);
            }
        }
        sort(res.begin(), res.end());
                return res;
         
    }
};