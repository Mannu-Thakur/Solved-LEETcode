class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string>res;
        int  n = names.size();

        vector<pair<int, string>>temp;
        for(int i=0; i<n; ++i){
            temp.push_back({heights[i], names[i]});
        }

        sort(temp.rbegin(), temp.rend());
        for(auto &f: temp){
            res.push_back(f.second);
        }
        return res;
    }
};