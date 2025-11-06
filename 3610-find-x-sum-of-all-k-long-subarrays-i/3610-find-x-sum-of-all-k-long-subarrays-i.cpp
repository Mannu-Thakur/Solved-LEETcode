 
 

class Solution {
    static bool cmp(pair<int,int> &a, pair<int,int> &b) {
        if (a.second == b.second)
            return a.first > b.first;  
        return a.second > b.second;  
    }

    long long solve(vector<int> &nums, int s, int e, int k, int x) {
        unordered_map<int, int> mp;
        for (int i = s; i <= e; i++)
            mp[nums[i]]++;

        vector<pair<int,int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), cmp);

        long long sum = 0;

        if ((int)v.size() < x) {
             
            sum = accumulate(nums.begin() + s, nums.begin() + e + 1, 0LL);
        } else {
             for (int i = 0; i < x; i++)
                sum += (1LL * v[i].first * v[i].second);
        }

        return sum;
    }

public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i + k - 1 < n; i++) {
            ans.push_back(solve(nums, i, i + k - 1, k, x));
        }

        return ans;
    }
};
