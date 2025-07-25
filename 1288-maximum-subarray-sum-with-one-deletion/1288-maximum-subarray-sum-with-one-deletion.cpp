class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        long long maxSum = arr[0];
        long long noDel = arr[0];
        long long oneDel = LLONG_MIN;

        for (int i = 1; i < n; ++i) {
            // Only add to oneDel if it's not LLONG_MIN to avoid overflow
            if (oneDel == LLONG_MIN)
                oneDel = noDel;  // delete current element
            else
                oneDel = max(noDel, oneDel + arr[i]);

            noDel = max((long long)arr[i], noDel + arr[i]);
            maxSum = max({maxSum, noDel, oneDel});
        }

        return static_cast<int>(maxSum);
    }
};
