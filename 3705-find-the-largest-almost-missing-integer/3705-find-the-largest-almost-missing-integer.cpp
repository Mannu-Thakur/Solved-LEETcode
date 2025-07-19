class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == k){
             return *max_element(nums.begin(), nums.end());
        }

        unordered_map<int, int> count;

        for(int i = 0; i <= n - k; ++i){
            unordered_set<int> seen;
            for(int j = i; j < i + k; ++j){
                count[nums[j]]++;
            }
            
        }

        int ans = -1;
        for(auto& [num, cnt] : count){
            if(cnt == 1){
                ans = max(ans, num);
            }
        }

        return ans;
    }
};
