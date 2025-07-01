class Solution {
    bool isVowel(char ch) {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
public:
    string reverseVowels(string s) {
        vector<int> ind;  // to store indices of vowels

        // collect vowel indices
        for (int i = 0; i < s.length(); ++i) {
            if (isVowel(s[i])) {
                ind.push_back(i);
            }
        }

        // reverse the vowels using their indices
        int i = 0, j = ind.size() - 1;
        while (i < j) {
            swap(s[ind[i]], s[ind[j]]);
            i++;
            j--;
        }

        return s;
    }
};
