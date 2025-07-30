class Solution {
    bool solve(  string &s, int n){
        if(s.size() == 2){
            return s[0] == s[1];
        }
        

        string temp = "";
        for(int i=0; i<n-1; ++i){
            int a = (int)s[i];
            int b = (int)s[i+1];
            int mod = (a+b) % 10;
            temp.push_back(mod);
        }

        return solve(temp, temp.size());
    }
public:
    bool hasSameDigits(string s) {
        int n = s.length();
       return solve( s, n);
    }
};