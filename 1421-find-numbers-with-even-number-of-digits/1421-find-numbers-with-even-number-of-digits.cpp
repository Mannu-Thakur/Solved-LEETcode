class Solution {
    int solve(int num){
        int cnt = 0;
        while(num > 0){
            num /= 10;
            cnt++;
        }

        return cnt;
    }
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int cnt  = 0;
        for(auto &f: nums){
          int temp  =  solve(f);
          if(temp % 2 == 0) cnt++;
        }
        return cnt;
    }
};