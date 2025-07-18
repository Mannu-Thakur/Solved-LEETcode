class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> points;
        int max_num = 0;
        
        for(int num : nums){
            points[num] += num;
            max_num = max(max_num, num);
        }
        
        int pick = 0, not_pick = 0;
        
        for(int i = 0; i <= max_num; ++i){
            int curr_pick = not_pick + points[i]; 
            int curr_not_pick = max(pick, not_pick);   
            
            pick = curr_pick;
            not_pick = curr_not_pick;
        }
        
        return max(pick, not_pick);
    }
};
