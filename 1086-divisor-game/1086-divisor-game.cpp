// class Solution {
    
// public:
//     bool divisorGame(int n) {
//         int x;
//         if( (0 <  x && x < n) && (n%x == 0) ){
//             n = n-x;
//             divisorGame(n);
//         }
//         if(n%2 == 0) return true;
//         else return false;

//     }
// };


// this solution used dp and more efficient than the above using the recursion.
class Solution{
    public:
    bool divisorGame(int n){
        vector<int>dp(n+1, false);
        dp[0] = false;
        dp[1] = false;
        for(int i=2; i<=n ; ++i){
            for(int j = 1; j<i;++j){
                if(i%j == 0 && !dp[i-j])
                dp[i]=true;
                break;
            }
        }
        return dp[n];
    }
};