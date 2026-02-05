class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();

        int cnt = 1;

        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){  // 3 < 4
              cnt++;
            }
            else{
                break;
            }
        }

        return n - cnt;
    }
};