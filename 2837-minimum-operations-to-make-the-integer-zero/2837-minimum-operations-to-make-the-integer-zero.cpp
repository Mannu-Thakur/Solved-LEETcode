class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int i = 0; i<=60; i++){
            long long x = num1 - 1LL*num2*i;

            if(x < i) continue;
            int cnt = __builtin_popcountll(x);
            if(cnt <= i) return i;
         
        }
        return -1;
    }
};