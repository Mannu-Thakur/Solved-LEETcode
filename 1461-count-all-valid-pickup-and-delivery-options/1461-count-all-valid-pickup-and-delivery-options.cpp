class Solution {
    int m = 1e9+7;
public:
    int countOrders(int n) {
        if(n == 1) return 1;
        long long res = 1;

        for(int i=2; i<=n; ++i){
            int spaces = (i-1)*2+1;
            int temp = (spaces+1)*spaces/2;
            res *= temp;
            res = res % m;
        }
        return res;
    }
};