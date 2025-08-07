class Solution {
    typedef long long ll;
    const int MOD = 1e9 + 7;

public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        // Step 1: Combine efficiency and speed in a pair
        vector<pair<int, int>> v;
        for(int i = 0; i < n; ++i){
            v.push_back({efficiency[i], speed[i]});
        }

        // Step 2: Sort by efficiency descending
        sort(v.rbegin(), v.rend());

        // Min-heap to keep k largest speeds
        priority_queue<int, vector<int>, greater<int>> pq;
        ll speedSum = 0, res = 0;

        // Step 3: Iterate through candidates
        for(auto &[e, s] : v){
            pq.push(s);
            speedSum += s;

            // If more than k speeds, remove the smallest
            if(pq.size() > k){
                speedSum -= pq.top();
                pq.pop();
            }

            // Update result: current min efficiency * total speed
            res = max(res, speedSum * e);
        }

        return res % MOD;
    }
};
