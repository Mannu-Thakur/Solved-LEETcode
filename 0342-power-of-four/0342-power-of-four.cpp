class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n > 0) && ((n & (n - 1)) == 0 && (n % 3 == 1));
    }
};


//((n & (n-1)) == 0 this only checks for the set bit and for the powers of 2 and 4 there is only one set bit