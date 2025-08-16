class Solution {
    bool oneCharDiff(string &a, string &b) {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) cnt++;
            if (cnt > 1) return false;
        }
        return cnt == 1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0; // if endWord is not present then return 0;

        queue<pair<string,int>> q;
        q.push({beginWord, 1});

        while(!q.empty()) {
            auto [word, steps] = q.front(); 
            q.pop(); 
            
            if (word == endWord) return steps;

            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (dict.count(temp)) {
                        q.push({temp, steps+1});
                        dict.erase(temp); // avoid revisiting
                    }
                }
            }
        }
        return 0;
    }
};
