class Solution {
    const int MOD = 1e9 + 7;

    string solve(int n) {
        string s = bitset<32>(n).to_string();
        return s.substr(s.find('1'));   // remove leading zeros
    }

    long long resolve(const string& s) {
        long long result = 0;
        for (char c : s) {
            result = (result * 2 + (c - '0')) % MOD;
        }
        return result;
    }

public:
    int concatenatedBinary(int n) {
        string temp = "";

        for (int i = 1; i <= n; ++i) {
            temp += solve(i);
        }

        return resolve(temp);
    }
};