class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char, int> chh;
        unordered_map<int, int> intt;

        // count frequencies
        for(char f : s){
            if(isdigit(f)){
                intt[f - '0']++;
            } else {
                chh[f]++;
            }
        }

        int ans = 0;
        unordered_set<char> visited;

        for(char x : s){
            if(visited.count(x)) continue;

            char y;
            if(isdigit(x)){
                y = '0' + (9 - (x - '0'));
            } else {
                y = 'a' + ('z' - x);
            }

            int x_f = isdigit(x) ? intt[x - '0'] : chh[x];
            int y_f = isdigit(y) ? intt[y - '0'] : chh[y];

            ans += abs(x_f - y_f);

            visited.insert(x);
            visited.insert(y);
        }

        return ans;
    }
};