class Solution {
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }

public:
    string sortVowels(string s) {
        string ans = "";
        int n = s.length();

        vector<char>vowels;
        for(auto &f: s){
            if(isVowel(f)){
                vowels.push_back(f);
            }
        }

        sort(vowels.begin(), vowels.end());

        int j = 0;
        for(int i=0; i<n; ++i){
            if(isVowel(s[i])){
                s[i] = vowels[j++];
            }
        }

        return s;

    }
};