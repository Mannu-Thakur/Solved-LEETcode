class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& bhasha, vector<vector<int>>& dosti) {
        int users = bhasha.size();

         vector<unordered_set<int>> knows(users+1);
        for (int i = 0; i < users; ++i) {
            for (auto &f : bhasha[i]) {
                knows[i+1].insert(f);
            }
        }

         unordered_set<int> needTeach;
        for (auto &f : dosti) {
            int a = f[0], b = f[1];
            bool canTalk = false;
            for (int lang : knows[a]) {
                if (knows[b].count(lang)) {
                    canTalk = true;
                    break;
                }
            }
            if (!canTalk) {
                needTeach.insert(a);
                needTeach.insert(b);
            }
        }

        if (needTeach.empty()) return 0;  

         vector<int> freq(n+1, 0);
        for (int u : needTeach) {
            for (int lang : knows[u]) {
                freq[lang]++;
            }
        }

         int maxKnown = 0;
        for (int lang = 1; lang <= n; ++lang) {
            maxKnown = max(maxKnown, freq[lang]);
        }

         return needTeach.size() - maxKnown;
    }
};
