class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int n = nums.size();
        
        int left = (n + 1) / 2 - 1; 
        int right = n - 1;          
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums[i] = sorted[left--];  
            } else {
                nums[i] = sorted[right--];  
            }
        }
    }
};
