class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int cnt = 0, ans = 0;

        int i = 0, j = 0;
        while (j < n) {
            if (isVowel(s[j])) cnt++;

            if (j - i + 1 > k) {
                if (isVowel(s[i])) 
                cnt--;
                i++;
            }
 
            if (j - i + 1 == k) {
                ans = max(ans, cnt);
            }

            j++;
        }

        return ans;
    }
};
