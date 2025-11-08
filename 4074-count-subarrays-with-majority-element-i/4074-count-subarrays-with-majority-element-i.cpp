 

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> a(n);
        for(int i=0;i<n;i++){
            a[i] = (nums[i] == target ? 1 : -1);
        }

        // prefix sum
        vector<int> pref(n+1, 0);
        for(int i=0;i<n;i++){
            pref[i+1] = pref[i] + a[i];
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                // sum a[i..j] = pref[j+1]-pref[i]
                if(pref[j+1]-pref[i] > 0) ans++;
            }
        }
        return ans;
    }
};
