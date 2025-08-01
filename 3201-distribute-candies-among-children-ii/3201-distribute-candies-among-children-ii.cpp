class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0;

        // child1
        int minCh1 = max(0, n - 2 * limit);
        int maxCh1 = min(n, limit);

        for (int i = minCh1; i <= maxCh1; i++) {  // fixing child1 assignment of candies
            int N = n - i;  // remaining candies for child2 and child3

            int minCh2 = max(0, N - limit);
            int maxCh2 = min(N, limit);

            ways += maxCh2 - minCh2 + 1;
        }

        return ways;
    }
};
