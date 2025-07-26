class Solution {
public:
    bool isSubsequence(string s, string t) {

        int n = s.length();
        int m = t.length();

        if(n == 0) return true;
        int i = 0;
        int j = 0;
        int cnt = 0;

        while(i < n && j < m){
            if(s[i] != t[j]){
                j++;
            }
            else if(s[i] == t[j]){
                i++;
                j++;
                cnt++;
                if(cnt == n) return true;
            }
        }
        return false;

    }
};