class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<pair<int, int>> q; // {current value, operations}
        vector<bool> visited(1001, false); // valid values: 0 to 1000

        q.push({start, 0});
        visited[start] = true;

        while (!q.empty()) {
            auto [num, ops] = q.front();
            q.pop();

            for (int val : nums) {
                vector<int> next = {num + val, num - val, num ^ val};

                for (int new_num : next) {
                    if (new_num == goal) return ops + 1;

                    if (new_num >= 0 && new_num <= 1000 && !visited[new_num]) {
                        visited[new_num] = true;
                        q.push({new_num, ops + 1});
                    }
                }
            }
        }

        return -1;
    }
};
