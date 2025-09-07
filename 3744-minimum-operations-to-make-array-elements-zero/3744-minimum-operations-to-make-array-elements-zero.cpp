class Solution {
    typedef long long lng;

    lng solve(int l, int r){
        lng L = 1;
        lng cnt = 0;
        lng s = 1;

        while(L <= r){
            lng R = 4*L-1;

            lng start = max(L, (lng)l);
            lng end = min(R, (lng)r);

            if(start <= end){
                cnt += (end - start + 1)*s;
            }

            L = 4*L;
            s += 1;
        }

        return cnt;

    }


public:
    long long minOperations(vector<vector<int>>& queries) {
        int n = queries.size();
        lng ans = 0;

        for(auto &f: queries){
            int l = f[0];
            int r = f[1];

            lng steps = solve(l, r);
            ans += (steps+1)/2;
        }

        return ans;
    
    }
};