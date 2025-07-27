class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        
        int total = accumulate(nums.begin(), nums.end(), 0);
        int currSum = 0;
        vector<int> res;

        for (int num : nums) {
            currSum += num;
            res.push_back(num);
            if (currSum > total - currSum)
                break;
        }

        return res;
    }
};
