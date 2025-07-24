class Solution {
    bool solve(string &s, int i, int j){
        unordered_set<char> vowels;
        for(int k = i; k <= j; ++k){
            if(s[k] == 'a' || s[k] == 'e' || s[k] == 'i' || s[k] == 'o' || s[k] == 'u'){
                vowels.insert(s[k]);
            } else {
                return false;   
            }
        }
        return vowels.size() == 5;
    }
public:
    int countVowelSubstrings(string word) {
        int n = word.size();
        int cnt = 0;

        for(int i = 0; i < n; ++i){
            for(int j = i; j < n; ++j){
                if(solve(word, i, j)){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
