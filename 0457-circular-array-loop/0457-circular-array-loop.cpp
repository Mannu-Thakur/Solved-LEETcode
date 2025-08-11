class Solution {
public:
    int nextIndex(vector<int>& nums, int curr, bool forward) {
    int n = nums.size();
    bool dir = nums[curr] > 0;
    if (dir != forward) return -1; // direction changed → invalid
    int next = (curr + nums[curr]) % n;
    if (next < 0) next += n;
    if (next == curr) return -1; // single-element loop
    return next;
}

bool circularArrayLoop(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        bool forward = nums[i] > 0;
        int slow = i, fast = i;

        while (true) {
            slow = nextIndex(nums, slow, forward);
            if (slow == -1) break;

            fast = nextIndex(nums, fast, forward);
            if (fast == -1) break;
            fast = nextIndex(nums, fast, forward);
            if (fast == -1) break;

            if (slow == fast) return true;
        }
    }
    return false;
}

};