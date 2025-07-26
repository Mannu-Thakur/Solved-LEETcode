class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int sum1 = 0;

        for(auto &f: nums){
            if( f <= 9 && f >= 1){
                sum += f;
            }

            else if( f >= 10 && f <= 99){
                sum1 += f;
            }
        }

        if( sum > sum1 || sum1 > sum){
            return true;
        }
        return false;
    }
};