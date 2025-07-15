class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        if (n < 3) return false;

        bool has_vowel = false;
        bool has_consonant = false;

        for (char ch : word) {
            if (!isalnum(ch)) return false;  // must be letter or digit

            if (isalpha(ch)) {
                char lower = tolower(ch);
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                    has_vowel = true;
                } else {
                    has_consonant = true;
                }
            }
        }

        return has_vowel && has_consonant;
    }
};
