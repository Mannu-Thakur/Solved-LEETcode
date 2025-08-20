class Solution {

   bool pal(string &s) {
    int n = s.length();
    for (int i = 0; i < n/2; ++i) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
   }

    string temp = "";
    void solve(int n, int base){
        while(n > 0){
            int rem = n % base;
            temp += rem;
            n /= base;

        }
        reverse(temp.begin(), temp.end());
    }
    
public:
    bool isStrictlyPalindromic(int n) {
        for(int i=2; i <= n-2; ++i){
            solve(n, i);

            if(!pal(temp)){
                return false;
            }
        }
        return true;

    }
};