class Solution {
    void solve(int n, int last, int &cnt){
        if(n == 0){
            cnt++;
            return;
        }

        for(int i = 0; i<5; ++i){
            if(i >= last){
                solve(n-1, i, cnt);
            }
        }

    }
public:
    int countVowelStrings(int n) {
        if(n == 1) return 5;
        
        int cnt = 0;
         solve(n, 0, cnt);
         return cnt;
    }
};