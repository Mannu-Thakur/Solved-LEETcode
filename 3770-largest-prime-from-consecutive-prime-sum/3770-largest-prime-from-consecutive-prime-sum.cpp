class Solution {

    bool isPrime(int num){
        if(num <= 1) return false;
        for(int i=2; i*i <= num; ++i){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }

    void solve(vector<int>& primes, int n) {
        vector<bool> isPrimeArr(n + 1, true);
        isPrimeArr[0] = isPrimeArr[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrimeArr[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrimeArr[j] = false;
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            if (isPrimeArr[i]) primes.push_back(i);
        }
    }

public:
    int largestPrime(int n) {
        vector<int> primes;
        solve(primes, n);

        int sum = 0;
        int ans = 0;

        for (int p : primes) {
            if (sum + p > n) break;

            sum += p;

            if (isPrime(sum)) {
                ans = sum;   
            }
        }

        return ans;
    }
};
