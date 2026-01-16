class Solution {

    bool solve(double mid, vector<vector<int>>& squares){
        double above = 0, below = 0;

        for(auto &f: squares){
            double y = f[1];
            double s = f[2];

            if(mid <= y){
                above += s * s;
            }
            else if(mid >= y + s){
                below += s * s;
            }
            else{
                above += s * (y + s - mid);
                below += s * (mid - y);
            }
        }
        return below < above;
    }

public:
    double separateSquares(vector<vector<int>>& squares) {

        double low = 1e18, high = -1e18;

        for(auto &sq : squares){
            double y = sq[1];
            double s = sq[2];
            low = min(low, y);
            high = max(high, y + s);
        }

        for(int i = 0; i < 80; i++){
            double mid = (low + high) / 2.0;

            if(solve(mid, squares)){
                low = mid;
            }else{
                high = mid;
            }
        }
        return low;
    }
};
