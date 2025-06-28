class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for(int i = 0; i < nums.size(); i++){
            q.push({nums[i], i});
            if (q.size() > k) {
                q.pop();
            }
        }
        map<int,int> m;// 
        while(!q.empty()){
            m.insert({q.top().second,q.top().first});
            q.pop();
        }
        vector<int>ans;
        for(auto &s: m){
            ans.push_back(s.second);
        }

        return ans;
    }
};