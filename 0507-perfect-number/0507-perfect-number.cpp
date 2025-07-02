class Solution {
    vector<int> getDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) // avoid duplicate for perfect squares
                divisors.push_back(n / i);
        }
    }
    sort(divisors.begin(), divisors.end()); // optional
    return divisors;
}

public:
    bool checkPerfectNumber(int num) {
        vector<int>res = getDivisors(num);
        int sum  =0;
        for(int i=0; i<res.size()-1; ++i){
            sum += res[i];
        }
        return sum == num;
    }
};