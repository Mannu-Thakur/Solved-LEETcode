class Solution {
public:
    long long gcdll(long long a, long long b){
        return b==0 ? a : gcdll(b, a%b);
    }

    long long lcmll(long long a, long long b){
        return (a / gcdll(a,b)) * b;
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long l = 1, r = 1e18;
        long long L = lcmll(a,b);
        long long ans = 0;

        while(l <= r){
            long long mid = l + (r-l)/2;

            long long cnt = mid/a + mid/b - mid/L;

            if(cnt >= n){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return ans % 1000000007;
    }
};
