class Solution {
    double diag(int l, int b) {
        return sqrt(1.0 * l * l + 1.0 * b * b);
    }

    int area(int l, int b) {
        return l * b;
    }

public:
    int areaOfMaxDiagonal(vector<vector<int>>& mat) {
        int n = mat.size();

        double dg = 0;  
        int ar = 0;    

        for (int i = 0; i < n; ++i) {
            int x = mat[i][0];
            int y = mat[i][1];

            double d = diag(x, y);
            int a = area(x, y);

            if (d > dg) {
                dg = d;
                ar = a;
            } else if (d == dg) {
                ar = max(ar, a);
            }
        }
        return ar;
    }
};
