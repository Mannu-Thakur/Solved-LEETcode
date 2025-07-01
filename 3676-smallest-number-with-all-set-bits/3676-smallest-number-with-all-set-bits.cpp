class Solution {
public:
    int smallestNumber(int n) {
        vector<int> res;

        int val = 1;
        while (val <= n) {
            res.push_back(val);
            val *= 2;
        }

        // Now val is the first power of 2 greater than n
        return val - 1;
    }
};
