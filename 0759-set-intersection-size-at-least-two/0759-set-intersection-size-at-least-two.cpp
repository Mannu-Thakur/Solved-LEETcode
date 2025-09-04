class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& nums) {

        sort(nums.begin(), nums.end(), [](const vector<int>&a, const vector<int>&b){
            if(a[1] == b[1]){
                return a[0] > b[0];
            }else{
                return a[1] < b[1]; 
            }
        });

        int s = -1;
        int e = -1;
        int ans = 0;

        for(auto &it: nums){
            int a = it[0];
            int b = it[1];

            if(a <= s){
                continue;
            }else if(a > e){
                ans += 2;
                s = b-1;
                e = b;
            }else{
                ans += 1;
                s = e;
                e = b;
            }
        }
        return ans;
    }
};