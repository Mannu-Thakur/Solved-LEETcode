class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();

        unordered_map<int, int>mpp;

        for(auto &f: nums){
            int rem = ((f % value) + value ) % value;
            mpp[rem]++;

        }

        int ans = 0;

        while(mpp[ans % value] > 0){
            mpp[ans % value]--;
            ans++;
        }
        return ans;
    }
};


// so in order to find the the smallest we need to find the remainders.
// we got to have a map;