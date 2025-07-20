class Solution {
public:
    typedef pair<int, int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mpp;
        
        for(auto &find : nums) {
            mpp[find]++;
        }

        priority_queue<p, vector<p>, greater<p>> pq;

        for(auto &it : mpp) {
            pq.push({it.second, it.first});
            if(pq.size() > k) {
                pq.pop();
            }
        }

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
