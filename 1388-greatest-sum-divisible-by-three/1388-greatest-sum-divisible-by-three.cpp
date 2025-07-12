class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int arr[2][3];
        arr[0][0] = arr[0][1] = arr[0][2] = 0;
        arr[1][0] = arr[1][1] = arr[1][2] = 0;

        for (int i = 0; i < n; i++) {
            // Copy the current state to avoid in-place modification during loop
            for (int j = 0; j < 3; j++) {
                arr[1][j] = arr[0][j];
            }

            for (int j = 0; j < 3; j++) {
                int modClass = (arr[0][j] + nums[i]) % 3;
                arr[1][modClass] = max(arr[1][modClass], arr[0][j] + nums[i]);
            }

            // Also consider nums[i] alone
            int modClass = nums[i] % 3;
            arr[1][modClass] = max(arr[1][modClass], nums[i]);

            // Copy back to arr[0]
            for (int j = 0; j < 3; j++) {
                arr[0][j] = arr[1][j];
            }
        }

        return arr[0][0];
    }
};
