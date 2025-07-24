class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // Step 1: Convert each tap to a range [start, end]
        vector<pair<int, int>> intervals;
        for(int i = 0; i <= n; ++i) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            intervals.push_back({left, right});
        }

        // Step 2: Sort by start, and if equal, by further end descending (optional for greedy)
        sort(intervals.begin(), intervals.end());

        // Step 3: Greedy selection of intervals
        int taps = 0, i = 0, farthest = 0, curr_end = 0;
        
        while (curr_end < n) {
            while (i <= n && intervals[i].first <= curr_end) {
                farthest = max(farthest, intervals[i].second);
                i++;
            }
            if (farthest == curr_end) return -1; // can't move forward
            curr_end = farthest;
            taps++;
        }

        return taps;
    }
};
