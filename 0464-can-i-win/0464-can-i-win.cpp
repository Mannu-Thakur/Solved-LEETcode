class Solution {
    unordered_map<int, bool> memo;

    bool solve(int usedMask, int maxChoosable, int target) {
        if (memo.count(usedMask)) return memo[usedMask];

        for (int i = 1; i <= maxChoosable; ++i) {
            int bit = 1 << (i - 1);
            if ((usedMask & bit) == 0) {
                // If picking i meets or exceeds target, or forces opponent to lose
                if (i >= target || !solve(usedMask | bit, maxChoosable, target - i)) {
                    return memo[usedMask] = true;
                }
            }
        }

        return memo[usedMask] = false;
    }

public:
    bool canIWin(int maxChoosable, int desiredTotal) {
        int maxSum = (maxChoosable * (maxChoosable + 1)) / 2;
        if (maxSum < desiredTotal) return false;
        if (desiredTotal <= 0) return true;

        return solve(0, maxChoosable, desiredTotal);
    }
};
