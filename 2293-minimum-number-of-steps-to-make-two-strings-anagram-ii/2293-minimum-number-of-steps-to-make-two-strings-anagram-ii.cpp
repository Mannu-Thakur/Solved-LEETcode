class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int,int>mp;

        for(auto &f: s){
            mp[f]++;
        }
        for(auto &f: t){
      
                mp[f]--;
           
            
        }

        int cnt = 0;
        for(auto &f: mp){
            cnt += abs(f.second);
        }

        return cnt;
    }
};