class Solution {
    typedef long long ll;

    bool canCompleteInTime(ll mid, vector<int>& time, int x) {
        ll cnt = 0;
        for(int t : time) {
            cnt += mid / t;  // how many tasks this worker can do in `mid` minutes
            if(cnt >= x) return true;  // early stopping
        }
        return false;
    }

public:
    long long minimumTime(vector<int>& time, int x) {
        ll left = 1;
        ll right = 1LL * *min_element(time.begin(), time.end()) * x; // upper bound

        ll res = right;

        while(left <= right) {
            ll mid = left + (right - left) / 2;
            if(canCompleteInTime(mid, time, x)) {
                res = mid;
                right = mid - 1;  // try smaller time
            } else {
                left = mid + 1;   // need more time
            }
        }

        return res;
    }
};
