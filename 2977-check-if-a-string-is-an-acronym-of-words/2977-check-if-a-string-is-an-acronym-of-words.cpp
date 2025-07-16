class Solution {
    char solve(string &s){
        return s[0];
    }
public:
    bool isAcronym(vector<string>& words, string s) {
        int n = words.size();
        int len = s.length();

        string temp = "";
        for(auto &f: words){
            temp += solve(f);
        }

        if(temp.length() != len) return false;
        for(int i=0; i<temp.length(); ++i){
            if(s[i] != temp[i]){
                return false;
            }
        }
        return true;
    }
};