class Solution {
public:
    string truncateSentence(string s, int k) {
        int n = s.length();
        string ans = "";

        stringstream ss(s);
        string word  = "";
        while( ss >> word){
            ans += word;
            k--;

            if(k == 0) return ans;
            ans += " ";
        }

        return ans;
    }
};