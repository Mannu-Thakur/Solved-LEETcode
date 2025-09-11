// class Solution {
//     bool isVowel(char c) {
//     return (c == 'a' || c == 'e' || c == 'i' || 
//             c == 'o' || c == 'u' || 
//             c == 'A' || c == 'E' || c == 'I' || 
//             c == 'O' || c == 'U');
// }

// public:
//     string sortVowels(string s) {
//         int n = s.length();
//         vector<int>res(n);


//         for(int i=0; i<n-1; ++i){
//             if(!isVowel(s[i]) && (s[i] - '0') < (s[i+1] < '0')){
//                 res.push_back(s[i]);
//             }else{
//                 res[i] = s[i];
//             }
//         }

//         string ans = "";
//         for(auto &f: res){
//             ans += f;
//         }

//         return ans;
//     }
// };

class Solution {
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || 
                c == 'o' || c == 'u' || 
                c == 'A' || c == 'E' || c == 'I' || 
                c == 'O' || c == 'U');
    }

public:
    string sortVowels(string s) {
        vector<char> vowels;

         
        for (char c : s) {
            if (isVowel(c)) vowels.push_back(c);
        }
        sort(vowels.begin(), vowels.end());
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[j++];
            }
        }

        return s;
    }
};
