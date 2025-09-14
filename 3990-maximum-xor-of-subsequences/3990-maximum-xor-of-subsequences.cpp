class Solution {
public:

    int maxXorSubsequences(vector<int>& nums) {
    int n = nums.size();
    int basis[32] = {0};  
    for (int x : nums) {
        for (int i = 31; i >= 0; i--) {
            if (!(x & (1 << i))) continue;

            if (!basis[i]) { 
                basis[i] = x; 
                break;
            }
            x ^= basis[i];
        }
    }

     int res = 0;
    for (int i = 31; i >= 0; i--) {
        res = max(res, res ^ basis[i]);
    }
    return res;
}

};