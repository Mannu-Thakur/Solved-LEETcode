class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        
        int n = words.size();

        unordered_map<string, int>mp;

        for(auto &f: words){
            if(f.size() < k) continue;

            string str = f.substr(0, k);
            mp[str]++;
        }

        int cnt = 0;
        for(auto &f: mp){
            if(f.second > 1){
                cnt++;
            }
        }

        return cnt;
    }
};