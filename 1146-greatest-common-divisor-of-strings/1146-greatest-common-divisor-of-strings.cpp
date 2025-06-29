class Solution {
public:
    string gcdOfStrings(string s, string t) {
        if (s + t != t + s) return "";

        int gcdLen = gcd(s.size(), t.size());
        return s.substr(0, gcdLen);
    }

private:
    int gcd(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }
};
