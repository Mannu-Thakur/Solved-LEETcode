class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;  // avoid division by 0
        int right = *max_element(nums.begin(), nums.end());
        int res = -1;

        while(left <= right){
            int mid = left + (right - left)/2;
            int sum = 0;

            for(auto &f: nums){
                sum += (f + mid - 1)/mid;   
            }

            if(sum <= threshold){
                res = mid;           
                right = mid - 1;
            } else {
                left = mid + 1;     
            }
        }
        return res;
    }
};
