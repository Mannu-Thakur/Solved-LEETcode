class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        // int cnt =  count(nums.begin(), nums.end(), 0);

        int i=0;
        int ans = 0;
       
        int len = 0;
        while( i < n ){
            if(nums[i] == 0){
                i++;
                len++;
            }else{
                if(len > 0){
                    ans += 1LL*len*(len + 1)/2;
                    len = 0;
                }
                i++;

            }
        }

        ans += 1LL*len*(len + 1)/2;
        return ans ;
         
    }
};