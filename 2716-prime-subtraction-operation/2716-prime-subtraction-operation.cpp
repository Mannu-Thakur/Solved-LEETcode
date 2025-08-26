class Solution {
    vector<int> primes;

    void sieve() {
        int maxN = 1000;
        vector<bool> isPrime(maxN+1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= maxN; i++) {
            if (isPrime[i]) {
                for (int j = i*i; j <= maxN; j+=i)
                    isPrime[j] = false;
            }
        }
        for (int i = 2; i <= maxN; i++) {
            if (isPrime[i]) primes.push_back(i);
        }
    }

public:
    bool primeSubOperation(vector<int>& nums) {
        sieve();
        int n = nums.size();

        // Traverse from right to left
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) continue;

             bool possible = false;
            for (int p : primes) {
                if (p >= nums[i]) break;  
                if (nums[i] - p < nums[i+1]) {
                    nums[i] -= p;
                    possible = true;
                    break;
                }
            }
            if (!possible) return false;
        }
        return true;
    }
};
