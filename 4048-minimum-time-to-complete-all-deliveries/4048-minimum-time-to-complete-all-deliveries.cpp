class Solution {
public:

    bool check(long long time,vector<int>& d, vector<int>& r){
        long long w1 = time - time/r[0];
        long long w2 = time - time/r[1];

        if(d[0]>w1 || d[1]>w2){
            return false;
        }

        long long both = time/(lcm(r[0],r[1]));
        return d[0]+d[1]<=time-both;
    }
    long long minimumTime(vector<int>& d, vector<int>& r) {

        long long low =0;
        long long high = 1e18;
        long long ans = 1e18;

        while(low<=high){

            long long mid =(low+high)/2;

            if(check(mid,d,r)){
                ans = min(ans,mid);
                high =mid-1;
                
            }else{
                low =mid+1;
            }
        }
        return ans;
        
    }
};