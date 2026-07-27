class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int h = abs(fx - sx);
        int v = abs(fy - sy);

        int minTime = max(h, v);

        if( t < minTime || (t == 1 && (sx == fx && sy == fy))){
            return false;
        }


        return true;

    }
};