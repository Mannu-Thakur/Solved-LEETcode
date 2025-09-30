class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> res;
        long long fac = 1;

        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                res.push_back(digit * fac);
            }
            n /= 10;
            fac *= 10; 
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
