class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
       unordered_map<char, int>mp;
       for(auto &f: stones){
            mp[f]++;
       }

        int cnt = 0;
        for(auto &ch: jewels){
            if(mp.count(ch)){
                cnt += mp[ch];
                mp.erase(ch);
            }
        }

        return cnt;
    }
};