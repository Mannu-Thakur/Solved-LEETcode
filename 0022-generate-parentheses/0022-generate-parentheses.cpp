class Solution {
    void paren(int open, int close, string &ans, vector<string>&res){
        if(open ==0 && close == 0){
            res.push_back(ans);
            return ;
        }

        if(open > 0){
            ans.push_back('(');
            paren(open-1, close, ans, res);
            ans.pop_back();
        }
        if(close > 0){
            if(open < close){
                ans.push_back(')');
                paren(open, close-1, ans, res);
                ans.pop_back();
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
       
        vector<string>res;
        string ans;
        if(n>0){
            paren(n, n, ans, res);
        }
        return res;
          
    }
};