class Solution {
    string solve(string &s){
        int n = s.length();
        int read = 0;
        string res = ""; // to store result instead of appending to same string

        while(read < n){
            auto cnt = 0;               // changed auto -> int
            auto curr = s[read];       // changed auto -> char

            while(read < n && curr == s[read]){
                cnt++;
                read++;
            }

            // first-count, second-number itself
            if(cnt <= 9) {
                res.push_back(cnt + '0');   // convert to char
                res.push_back(curr);
            }
            else {
                int reps = (cnt + 9 - 1) / 9;
                while(reps--){
                    int temp = (cnt <= 9) ? cnt : 9;
                    cnt -= temp;
                    res.push_back(temp + '0');  // FIXED: use temp, not 9
                    res.push_back(curr);
                }
            }
        }
        return res;
    }
public:
    string compressedString(string word) {
        return solve(word);
    }
};
