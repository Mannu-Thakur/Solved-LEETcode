class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int cnt =0;
        sort(nums.begin(), nums.end());

        for(int i = n-1; i>=2; --i){
            int left = 0;
            int right = i-1;

            while(left < right){
             if ((long long)nums[left] + (long long)nums[right] > nums[i]) {
                   cnt += (right - left);
                     right--;
             }
                else{
                    left++;
                }
            }
        }

        return cnt;
    }
};