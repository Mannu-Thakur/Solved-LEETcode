class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int cost = 0;
        int n = colors.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; ++i) {
            // If new color starts, process the previous group
            if (i > 0 && colors[i] != colors[i - 1]) {
                // Remove all but the largest time in the group
                while (pq.size() > 1) {
                    cost += pq.top();
                    pq.pop();
                }
                // Clear heap for next group
                while (!pq.empty()) pq.pop();
            }

            // Push current time into group
            pq.push(time[i]);
        }

        // Process last color group
        while (pq.size() > 1) {
            cost += pq.top();
            pq.pop();
        }

        return cost;
    }
};
