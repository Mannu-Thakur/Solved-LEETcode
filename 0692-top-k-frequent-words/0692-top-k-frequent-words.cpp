class Solution {
    // Custom comparator for min-heap
    struct Compare {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first)
                return a.second < b.second;  
            return a.first > b.first;       
        }
    };

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto &w : words) {
            mp[w]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;

        for (auto &f : mp) {
            pq.push({f.second, f.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end()); 
        return res;
    }
};
