class Solution {
public:
     bool canSplit(vector<int>& nums, int k, int maxSum) {
        int count = 1;
        int currentSum = 0;

        for (int num : nums) {
            if (currentSum + num > maxSum) {
                count++;           
                currentSum = num;  
                if (count > k) return false;   
            } else {
                currentSum += num;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());   
        int high = accumulate(nums.begin(), nums.end(), 0);  
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                result = mid;      
                high = mid - 1;
            } else {
                low = mid + 1;    
            }
        }

        return result;
    }
};
