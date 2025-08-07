class Solution {
public:
    const int MOD = 1e9 + 7;
 
    unordered_map<long long, long long> dp;

    long long count(int cur_goal, int old_songs, int n, int k) {
       
        if (cur_goal == 0 && old_songs == n) return 1;
        if (cur_goal == 0 || old_songs > n) return 0;

    
        long long key = ((long long)cur_goal << 32) | old_songs;
        if (dp.count(key)) return dp[key];

        long long res = 0;

         if (n - old_songs > 0) {
            res += (n - old_songs) * count(cur_goal - 1, old_songs + 1, n, k);
            res %= MOD;
        }

         if (old_songs > k) {
            res += (old_songs - k) * count(cur_goal - 1, old_songs, n, k);
            res %= MOD;
        }

        return dp[key] = res;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        dp.clear();  
        return count(goal, 0, n, k);
    }
};
