 

class Solution {
public:
    // Function to find "kernel" of a number (product of primes with odd exponent)
    long long kernel(long long x) {
        long long res = 1;
        for (long long p = 2; p * p <= x; ++p) {
            int odd = 0;
            while (x % p == 0) {
                x /= p;
                odd ^= 1;  // toggle if prime appears odd number of times
            }
            if (odd) res *= p;
        }
        if (x > 1) res *= x;  // remaining prime
        return res;
    }

    void dfs(int u, int parent, vector<vector<int>>& graph,
             vector<long long>& k, unordered_map<long long, int>& freq, long long& ans) {
        
        long long ku = k[u];
        ans += freq[ku];      // count how many ancestors have same kernel
        freq[ku]++;           // include current node in frequency map

        for (int v : graph[u]) {
            if (v != parent)
                dfs(v, u, graph, k, freq, ans);
        }

        // remove current node before returning (backtrack)
        freq[ku]--;
        if (freq[ku] == 0)
            freq.erase(ku);
    }

    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<long long> k(n);
        for (int i = 0; i < n; ++i)
            k[i] = kernel(nums[i]);

        unordered_map<long long, int> freq;
        long long ans = 0;

        dfs(0, -1, graph, k, freq, ans);
        return ans;
    }
};
