class Solution {
    bool isVowel(char c) { 
    return (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u');
}

int solve(string &s){
    int n = s.length();
    int cnt = 0;

    for(int i=0; i<n;++i){
        if(isVowel(s[i])){
            cnt++;
        }
    }

    return cnt;
}
public:
    bool doesAliceWin(string s) {
        int n = s.length();
        bool flag = false;
        for(auto &f: s){
            if(isVowel(f)){
                flag = true;
            }
        }

        if(!flag){
            return false;
        }

        int xx = solve(s);
        if(xx % 2 == 1 ){
            return true;
        }
        return true;

    }
};