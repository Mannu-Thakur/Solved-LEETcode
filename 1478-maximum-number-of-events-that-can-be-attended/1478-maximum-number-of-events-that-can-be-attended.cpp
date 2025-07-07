 

class Solution {
    // Unused in final solution (optional)
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());  

         
        priority_queue<int, vector<int>, greater<int>> pq;

        int i = 0, n = events.size();
        int day = 0, attended = 0;
 
        while (!pq.empty() || i < n) {
            // If heap is empty, jump to next event's start day
            if (pq.empty()) {
                day = events[i][0];
            }

            // Push all events starting today or earlier into the heap
            while (i < n && events[i][0] <= day) {
                pq.push(events[i][1]); // push end day
                ++i;
            }

            // Remove expired events
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            // Attend the event that ends earliest
            if (!pq.empty()) {
                pq.pop(); // attend this event
                ++attended;
            }

            ++day; // move to next day
        }

        return attended;
    }
};
