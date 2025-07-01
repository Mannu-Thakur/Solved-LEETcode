class Solution {
    void reverse(int ind, string &s, int k) {
        int end = min((int)s.length(), ind + k);   
        for (int i = 0; i < (end - ind) / 2; ++i) {
            swap(s[ind + i], s[end - i - 1]);
        }
    }

public: 
    string reverseStr(string s, int k) {
        int n = s.length();

        for (int i = 0; i < n; i += 2 * k) {
            reverse(i, s, k); 
            
        }

        return s;
    }
};
