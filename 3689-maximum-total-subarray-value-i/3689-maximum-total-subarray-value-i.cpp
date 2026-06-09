class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();


        int mini = *min_element(nums.begin(), nums.end());
        int maxi =*max_element(nums.begin(), nums.end());

        int diff = abs(maxi-mini);
        return (long long)diff * k;
        
    }
};