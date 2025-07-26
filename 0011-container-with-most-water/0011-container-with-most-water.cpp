class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        long long water = 0;
        int i = 0;
        int j = n - 1;
        
        while (i < j) {
            long long area = (j - i) * min(height[i], height[j]);
            water = max(water, area);
            
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        
        return water;
    }
};
