class Solution {
    void solve(vector<int>& cand, int target, int ind, vector<vector<int>>& ans, vector<int>& temp) {
        if (target == 0) { 
            ans.push_back(temp);
            return;
        }

        if (ind >= cand.size() || target < 0) { 
            return;
        }

        temp.push_back(cand[ind]);
        solve(cand, target - cand[ind], ind, ans, temp); 
        temp.pop_back(); 
        
        solve(cand, target, ind + 1, ans, temp);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, target, 0, ans, temp);
        return ans;
    }
};
