class Solution {
    void solve(string &s, unordered_map<int, vector<char>>&mpp, string curr, vector<string>&res, int ind ){
        if(ind == s.length()){
            res.push_back(curr);
            return;
        }

        int ele = s[ind] - '0';
        auto val = mpp[ele];

        for(int i=0; i<val.size(); ++i){
            curr.push_back(val[i]);
            solve(s, mpp, curr,res, ind+1 );
            curr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        
        unordered_map<int, vector<char>>mpp;
        if(digits.size() == 0) return {};
        vector<string>res;
        mpp[2] = {'a', 'b', 'c'};
        mpp[3] = {'d', 'e', 'f'};
        mpp[4] = {'g', 'h', 'i'};
        mpp[5] = {'j', 'k', 'l'};
        mpp[6] = {'m', 'n', 'o'};
        mpp[7] = {'p','q', 'r', 's'};
        mpp[8] = {'t','u','v'};
        mpp[9] = {'w', 'x', 'y', 'z'};

        solve(digits, mpp, "", res, 0);
        return res;
    }
};