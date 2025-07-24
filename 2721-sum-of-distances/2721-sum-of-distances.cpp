class Solution {
   typedef long long ll; 
public:
    vector<long long> distance(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) 
            mp[arr[i]].push_back(i);

        vector<ll> ans(n);

        for (auto it : mp) {
            vector<int> vec = it.second;

            ll sum = 0;
            for (int i : vec) 
                sum += (ll)i;

            ll currSum = 0, restSum = 0;
            for (int i = 0; i < vec.size(); i++) {
                restSum = sum - currSum - vec[i];

                ll forLeft = vec[i] * (ll)i - currSum;
                ll forRight = restSum - (vec[i] * (ll)(vec.size() - i - 1));

                ans[vec[i]] = forLeft + forRight;

                currSum += vec[i];
            }
        }

        return ans;
    }
};
