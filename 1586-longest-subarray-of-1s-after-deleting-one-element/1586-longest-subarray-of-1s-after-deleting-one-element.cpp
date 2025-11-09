class Solution {
    int countZero(vector<int>& v){
        int c = 0;
        for(int &x: v) if(x==0) c++;
        return c;
    }
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=0;
        vector<int> temp;
        bool zeroUsed = false;
        int len = 0;

        while(j < n){
            if(nums[j] == 1){
                temp.push_back(1);
            }
            else{ // nums[j] == 0
                if(!zeroUsed){
                    zeroUsed = true;
                    temp.push_back(0);
                } else {
                    // shrink until we remove a zero
                    while(i < j && zeroUsed){
                        if(temp[0] == 0) zeroUsed = false;
                        temp.erase(temp.begin());
                        i++;
                    }
                    temp.push_back(0);
                    zeroUsed = true;
                }
            }

      
            len = max(len, (int)temp.size() - 1);

            j++;
        }

        return len;
    }
};
