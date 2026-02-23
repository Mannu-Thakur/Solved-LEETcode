class Solution {
public:
    string maximumXor(string s, string t) {
        int n = s.size();
        
        int cnt1 = 0, cnt0 = 0;

        for(auto &f: t){
            if(f == '0'){
                cnt0++;
            }else{
                cnt1++;
            }
        }

        string ans = "";


        for(int i=0; i<n; ++i){
            if(s[i] == '1'){
                if(cnt0 > 0){
                    ans += '1';
                    cnt0--;
                }else{
                    ans += '0';
                    cnt1--;
                }
            }

            if(s[i] == '0'){
                if(cnt1 > 0){
                    ans += '1';
                    cnt1--;
                }else{
                    ans += '0';
                    cnt0--;
                }
            }
        }

        return ans;

    }
};