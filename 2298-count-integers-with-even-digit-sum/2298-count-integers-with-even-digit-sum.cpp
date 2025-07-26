class Solution {
    int solve(int num){
        int sum = 0;
        while(num > 0){
            int last = num % 10;
            num /= 10;
            sum += last;
        }

        return sum % 2 == 0 ? 1: 0;
    }
public:
    int countEven(int num) {
        int cnt = 0;
        for(int i = 1; i<=num; ++i){
           cnt += solve(i);
        }
        return cnt;
    }
};