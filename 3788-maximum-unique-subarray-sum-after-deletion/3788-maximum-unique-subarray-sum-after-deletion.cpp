class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        unordered_set<int>st;

        int maxi = *max_element(nums.begin(), nums.end());
        if(maxi < 0) return maxi;
        for(auto &f: nums){
            if(st.count(f)) continue;
            st.insert(f);
             if(f >= 0){
                sum += f;
             }
        }
        return sum;



    }
};