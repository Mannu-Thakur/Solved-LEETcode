class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        long long totalGas = accumulate(gas.begin(), gas.end(), 0LL);
        long long totalCost = accumulate(cost.begin(), cost.end(), 0LL);

        if (totalGas < totalCost) return -1;

        int start = 0;
        int tank = 0;

        for (int i = 0; i < n; ++i) {
            tank += gas[i] - cost[i];

            if (tank < 0) {
                // can't reach next station → reset start
                start = i + 1;
                tank = 0;
            }
        }

        return start;
    }
};
