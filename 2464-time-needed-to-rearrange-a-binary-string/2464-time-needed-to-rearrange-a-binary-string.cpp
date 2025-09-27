class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int res = 0, zeros = 0;
        for(int i = 0, n = s.length(); i < n; ++i){
            if(s[i] == '0') ++zeros;
            else if(zeros) res = max(res + 1 , zeros);
        }
        return res;
    }
};