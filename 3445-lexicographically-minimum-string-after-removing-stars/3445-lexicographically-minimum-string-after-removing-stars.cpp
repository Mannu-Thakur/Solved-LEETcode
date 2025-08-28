class Solution {
    typedef pair<char, int> p;

   struct cmp {
    bool operator()(const p &a, const p &b) const {
         if(a.first != b.first){
            return a.first < b.first;
         }

        return b.second > a.second;
    }
};


public:
    string clearStars(string s) {
        int n = s.length();
        priority_queue<p, vector<p>, cmp> pq;

        for (int i = 0; i < n; ++i) {
            if (s[i] != '*') {
                pq.push({s[i], i});
            } else {
                if (!pq.empty()) {
                    int ind = pq.top().second;
                    pq.pop();
                    s[ind] = '*';  
                }
            }
        }

        string ans = "";
        for (int i = 0; i < n; ++i) {
            if (s[i] != '*') ans += s[i];
        }

        return ans;
    }
};
