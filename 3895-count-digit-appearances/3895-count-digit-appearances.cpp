class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans = 0;
        int n = nums.size();

        for(auto &f: nums){
           
           while(f > 0){
            int l = f % 10;
            if( l == digit){
                ans++;
            }
            f /= 10;
           }
        }
        return ans;
    }
};