class Solution {
public:

    bool canFinish(vector<vector<int>>& tasks, int energy) {

        for (auto &t : tasks) {

            int actual = t[0];
            int minimum = t[1];

            if (energy < minimum)
                return false;

            energy -= actual;
        }

        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {

        sort(tasks.begin(), tasks.end(),
            [](auto &a, auto &b) {

                return (a[1] - a[0]) >
                       (b[1] - b[0]);
            });

        int low = 1;
        int high = 1e9;

        while (low < high) {

            int mid = low + (high - low) / 2;

            if (canFinish(tasks, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};