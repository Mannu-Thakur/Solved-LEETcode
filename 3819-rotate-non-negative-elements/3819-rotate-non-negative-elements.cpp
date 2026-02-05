class Solution {
   vector<int> rotate(const vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return nums;  
    if (n == 1) return nums;

    k %= n;
    vector<int> res(n);

    for (int i = 0; i < n; i++) {
        res[i] = nums[(i + k) % n]; // left rotation
    }
    return res;
}


public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> temp;

         for (int x : nums) {
            if (x >= 0) temp.push_back(x);
        }

         vector<int> rotated = rotate(temp, k);

         int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                nums[i] = rotated[j++];
            }
        }

        return nums;
    }
};
