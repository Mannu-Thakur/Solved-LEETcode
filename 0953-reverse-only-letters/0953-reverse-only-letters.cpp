class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.length();

        int left = 0;
        int right = n - 1;

        while (left <= right) {
            if (isalpha(s[left]) && isalpha(s[right])) {
                swap(s[left], s[right]);
                left++;
                right--;
            } else {
                if (!isalpha(s[left])) {
                    left++;
                }
                if (!isalpha(s[right])) {
                    right--;
                }
            }
        }
        return s;
    }
};
