class Solution {
    // Helper to get next character with wrap-around
    char nextChar(char c) {
        return (c == 'z') ? 'a' : c + 1;
    }

    string generateKChars(int k) {
        string word = "a";
        while (word.size() < k) {
            string next;
            for (char c : word) {
                next += nextChar(c);
            }
            word += next;
        }
        return word;
    }

public:
    char kthCharacter(int k) {
        string finalString = generateKChars(k);
        return finalString[k - 1];
    }
};
