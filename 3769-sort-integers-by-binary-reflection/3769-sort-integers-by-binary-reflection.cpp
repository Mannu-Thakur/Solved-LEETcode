class Solution {
    // Convert int → binary without leading zeros
    string toBinary(int n) {
        string s = bitset<32>(n).to_string();
        return s.substr(s.find('1'));  
    }
 
    long long binaryToDecimal(const string &s) {
        return stoll(s, nullptr, 2);
    }

public:
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<long long,int>> tempList;

        for (int x : nums) {
            string b = toBinary(x);             
            reverse(b.begin(), b.end());       
            long long reflected = binaryToDecimal(b);   

            tempList.push_back({reflected, x});
        }

    
        sort(tempList.begin(), tempList.end());
        vector<int> ans;
        for (auto &p : tempList) ans.push_back(p.second);

        return ans;
    }
};
