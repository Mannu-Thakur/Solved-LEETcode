class Solution {
    bool solve(string &s, string &t){
        int n= s.length();
        for(int i=0; i<n; ++i){
            for(int j=0; j<t.length(); ++j){
                if(s[i] == t[j]){
                    return false;
                }
            }
        }

        return true;
    }
public:
    int canBeTypedWords(string text, string x) {
        int n= text.length();
        int m = x.length();

        int cnt = 0;

        stringstream ss(text);
        string str;
        while(ss >> str){
            if(solve(str, x)){
                cnt++;

            }
        }
        return cnt;
    }
};