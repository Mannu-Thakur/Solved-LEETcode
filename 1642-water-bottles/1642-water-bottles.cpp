class Solution {
public:
    int numWaterBottles(int f, int e) {
        int res = f;
        int rem = 0;
        int left = f / e + f % e;
        res += f / e;

        while(left >= e){
            res += left / e;
             left = left / e + left % e;

        }

        return res;
    }
};