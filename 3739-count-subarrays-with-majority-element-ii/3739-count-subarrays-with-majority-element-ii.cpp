class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

         

        unordered_map<int, int>mpp;
        mpp[0] = 1; 
    

        int cumSum = 0;
        long long leftPoints = 0;
        long long result = 0;



        for(int i=0; i<n; ++i){
             if(nums[i] == target){
                leftPoints += mpp[cumSum];
                cumSum += 1;

             }else{
                cumSum -= 1;
                leftPoints -= mpp[cumSum];
             }
            mpp[cumSum] += 1;
            result += leftPoints;
        }

        return result;
    }
};