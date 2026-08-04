class Solution {
    long long a = 0, b = 0;
    int solve(int n, vector<int>&piles, int ind){
        if(ind == n/2){
            return a > b;
        }

        int temp = max(piles[ind], piles[n-ind-1]);
        int tem = min(piles[ind], piles[n-ind-1]);
        a += temp; // added to alice
        b += tem; // added to bob
       return solve(n, piles, ind+1);
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

       return solve(n, piles, 0);
    }
};