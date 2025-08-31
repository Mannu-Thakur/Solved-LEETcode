class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;
        int ans = 0;
        for(int i=0; i<n; ++i){
            mp[nums[i]]++;
        }

        for(auto &f: mp){
            if(f.second == 1){
                ans += f.first;
            }
        }
        return ans;
    }
};