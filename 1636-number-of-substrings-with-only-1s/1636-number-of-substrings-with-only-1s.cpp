class Solution {
public:
    int numSub(string s) {
        const long long MOD = 1e9 + 7;
        int n = s.length();
        
        long long cnt = 0;
        long long ans = 0;
        
        for(int i = 0; i < n; ++i){
            if(s[i] == '1'){
                cnt++;
            } else {
                if(cnt > 0){
                    ans = (ans + (cnt * (cnt + 1) / 2) % MOD) % MOD;
                    cnt = 0;
                }
            }
        }
        
        ans = (ans + (cnt * (cnt + 1) / 2) % MOD) % MOD;
        return (int)ans;
    }
};
