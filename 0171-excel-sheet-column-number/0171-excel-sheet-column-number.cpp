class Solution {
public:
    int titleToNumber(string col) {
        int res = 0;

        for(int i=0; i<col.length(); ++i){
            res = res*26 ;
            res += col[i]-'A'+1;
        }
        return res;
    }
};