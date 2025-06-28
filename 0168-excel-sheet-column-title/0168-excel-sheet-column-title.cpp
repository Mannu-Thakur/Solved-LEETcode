class Solution {
public:
    string convertToTitle(int x) {
        string res = "";
        while (x > 0) {
            x--; // to make it 0-indexed
            char ch = (x % 26) + 'A';
            res = ch + res;
            x /= 26;
        }
        return res;
    }
};
