class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> temp, high;

        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                temp.push_back(i);
                if (i != n / i) high.push_back(n / i);
            }
        }

        temp.insert(temp.end(), high.rbegin(), high.rend());

        if (k <= temp.size())
            return temp[k - 1];
        return -1;  
    }
};
