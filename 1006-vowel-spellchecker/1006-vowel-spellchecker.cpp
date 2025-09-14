class Solution {
    bool isVowel(char c) {
        c = tolower((unsigned char)c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    // convert a word to its "vowel-masked" form
    string maskVowels(const string &s) {
        string res = s;
        for (char &c : res) {
            if (isVowel(c)) c = '*';  // replace vowels with '*'
            else c = tolower(c);
        }
        return res;
    }

public:
    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        unordered_set<string> exact;                 // for rule 1
        unordered_map<string, string> caseMap;       // for rule 2
        unordered_map<string, string> vowelMap;      // for rule 3

        // preprocess wordlist
        for (string &w : wordlist) {
            exact.insert(w);

            string lower = w;
            for (char &c : lower) c = tolower(c);
            if (caseMap.find(lower) == caseMap.end())
                caseMap[lower] = w;  // keep first occurrence only

            string masked = maskVowels(w);
            if (vowelMap.find(masked) == vowelMap.end())
                vowelMap[masked] = w;
        }

        vector<string> res;
        for (string &q : queries) {
            if (exact.count(q)) {
                res.push_back(q);  // Rule 1
                continue;
            }

            string lower = q;
            for (char &c : lower) c = tolower(c);
            if (caseMap.count(lower)) {
                res.push_back(caseMap[lower]);  // Rule 2
                continue;
            }

            string masked = maskVowels(q);
            if (vowelMap.count(masked)) {
                res.push_back(vowelMap[masked]);  // Rule 3
                continue;
            }

            res.push_back("");  // Rule 4
        }
        return res;
    }
};
