class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.length();

        if(n == 1) return 1;
    int i=0;
       

        int len = 1, temp = 1;  
        for (int i = 1; i < n; i++) {
            if ((s[i] - '0') == (s[i - 1] - '0') + 1) {
                temp++;
                len = max(len, temp);
            } else {
                temp = 1;
            }
        }

        return len;
    }
};