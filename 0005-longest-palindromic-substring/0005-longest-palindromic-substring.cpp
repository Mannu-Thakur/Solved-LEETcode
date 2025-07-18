class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s; 
        int start = 0, maxLength = 0;

        for (int i = 0; i < n; i++) {
            
            expand(s, i, i, start, maxLength);
            expand(s, i, i + 1, start, maxLength);
        }
        
        return s.substr(start, maxLength);
    }
    
private:
    void expand(const string &s, int left, int right, int &start, int &maxLength) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        int length = right - left - 1; 
        if (length > maxLength) {
            start = left + 1; 
            maxLength = length; 
        }
    }
};
