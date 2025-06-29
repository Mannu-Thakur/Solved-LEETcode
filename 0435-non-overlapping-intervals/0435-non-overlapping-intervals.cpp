class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;
        
        sort(intervals.begin(), intervals.end(), compare);
        
        int lastEndTime = intervals[0][1];
        int count = 1;
        
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] >= lastEndTime) {
                count++;
                lastEndTime = intervals[i][1];
            } 
        }
        
        return n-count;
    }
};
