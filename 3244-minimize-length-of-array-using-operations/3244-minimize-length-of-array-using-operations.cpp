class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int min_val = *min_element(nums.begin(), nums.end());

        for (int x : nums) {
            if (x % min_val != 0)
                return 1;  // Cannot reduce this element
        }

        // Count how many elements equal to min_val
        int count = 0;
        for (int x : nums) {
            if (x == min_val) count++;
        }

        return (count + 1) / 2;
    }
};
