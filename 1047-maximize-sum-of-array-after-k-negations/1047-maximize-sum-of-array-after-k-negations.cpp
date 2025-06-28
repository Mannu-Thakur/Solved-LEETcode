class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<int, vector<int>, greater<int>>p;
        for(int i=0; i<n; ++i){
            p.push(nums[i]);
        }

        while(!p.empty() && k-- ){
            auto top = p.top();
            p.pop();

            top = -top;
            p.push(top);
        }

        int res = 0;
        while(!p.empty()){
            res += p.top();
            p.pop();
        }
        return res;
    }
};