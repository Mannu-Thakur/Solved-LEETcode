class Solution {
    typedef long long ll;
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll ans = 0;
        int n = nums.size();

        vector<ll> pref(n+1, 0);
        for(int i = 0; i < n; ++i){
            pref[i+1] = pref[i] + nums[i];
        }

        ll temp = 0;
        unordered_map<ll,ll> freq;

         for(int i = 0; i < k; ++i){
            temp += nums[i];
            freq[nums[i]]++;
        }

        if(freq.size() == k) ans = temp;

       
        for(int i = k; i < n; ++i){
            temp += nums[i];               
            freq[nums[i]]++;

            temp -= nums[i-k];           
            freq[nums[i-k]]--;
            if(freq[nums[i-k]] == 0) freq.erase(nums[i-k]);

            if(freq.size() == k){
                ans = max(ans, temp);
            }
        }

        return ans;
    }
};