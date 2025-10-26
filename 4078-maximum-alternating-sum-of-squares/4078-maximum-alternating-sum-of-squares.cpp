class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(auto &i:nums)i=abs(i);
        sort(nums.rbegin(),nums.rend());
        int n=nums.size();
        int i=0,j=n-1;
        long long x=0;
        while(i<j){
            x+=nums[i]*nums[i];
            x-=nums[j]*nums[j];
            i++;
            j--;
        }
        if(i==j)x+=nums[i]*nums[i];
        return x;
    }
};