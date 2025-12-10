class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        int n = t1.size();
        vector<pair<int, int>>v;

        for(int i=0; i<n; ++i){
            v.push_back({t1[i] - t2[i], i});
        }

        sort(v.rbegin(), v.rend());

        long long ans=0;

        for(int i=0; i<k; ++i){
            ans += t1[v[i].second];
        }

        for(int i=k; i<n; ++i){
            if(v[i].first > 0){
                ans += t1[v[i].second];
            }else{
                ans += t2[v[i].second];
            }
        }

        return ans;
    }
};