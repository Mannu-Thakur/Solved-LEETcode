class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
         int min_val = *min_element(nums.begin(), nums.end());
        for (int num : nums) {
            if (num % min_val != 0) return 1; 
        }

         int count = count_if(nums.begin(), nums.end(), [&](int x) {
            return x == min_val;
        });

        return (count + 1) / 2;  
    }
};
