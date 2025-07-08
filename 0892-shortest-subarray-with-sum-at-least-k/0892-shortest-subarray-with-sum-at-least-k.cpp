class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prsum(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            prsum[i + 1] = prsum[i] + nums[i];
        }

        deque<int> dq;
        int res = n + 1;

        for (int j = 0; j <= n; ++j) {
             while (!dq.empty() && prsum[j] - prsum[dq.front()] >= k) {
                res = min(res, j - dq.front());
                dq.pop_front();
            }

             while (!dq.empty() && prsum[j] <= prsum[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(j);
        }

        return (res == n + 1) ? -1 : res;
    }
};
