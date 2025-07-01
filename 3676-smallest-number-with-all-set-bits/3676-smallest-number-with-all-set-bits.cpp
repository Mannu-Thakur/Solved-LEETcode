class Solution {
public:
    int smallestNumber(int n) {
         

        int val = 1;
        while (val <= n) {
            val *= 2;
        }

        // Now val is the first power of 2 greater than n
        return val - 1;
    }
};
