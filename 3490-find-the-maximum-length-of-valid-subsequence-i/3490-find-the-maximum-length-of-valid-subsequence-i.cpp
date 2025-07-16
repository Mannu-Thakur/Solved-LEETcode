class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        int odd  = 0;
        int even = 0;

        for(auto &num : nums){
            if(num % 2 == 0) even++;
            else odd++;
        }

        int alt = 1;
        int parity = nums[0] % 2;
        for(auto &f: nums){
            int curpa = f % 2;

            if(curpa != parity){
                alt++; 
                 parity = curpa;
            }
            
        }

        return max({odd, even, alt});
    }
};