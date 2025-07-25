class Solution {
public:
    int maximumSum(vector<int>& a) {
        int n = a.size();
        long long res = a[0];
        long long nd = a[0];       // No deletion
        long long od = LLONG_MIN;  // One deletion

        for (int i = 1; i < n; ++i) {
            // only add od + a[i] if od is not LLONG_MIN
            if (od != LLONG_MIN)
                od = max(od + a[i], nd);
            else
                od = nd;

            nd = max((long long)a[i], nd + a[i]);
            res = max({res, nd, od});
        }

        return (int)res;
    }
};
