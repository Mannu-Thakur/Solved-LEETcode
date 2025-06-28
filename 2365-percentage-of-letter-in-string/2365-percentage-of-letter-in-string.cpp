class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.length();
        int p = count(s.begin(), s.end(), letter);

        return (p * 100) / n;
    }
};
