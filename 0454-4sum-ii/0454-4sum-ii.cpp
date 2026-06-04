class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // since we do not need to return the actual indices so we will use map to find the total count

        unordered_map<long long, long long>mp;
        int cnt = 0;

        long long target = 0, targot = 0;
        for(auto &f: nums1){
            for(auto &g: nums2){
               target = f + g;
               mp[target]++;
            }
        }

        for(auto &c: nums3){
            for(auto &d: nums4){
                targot = -(c + d);
                if(mp.find(targot) != mp.end()){
                    cnt += mp[targot];
                }
            }
        }


return cnt;

    }
};