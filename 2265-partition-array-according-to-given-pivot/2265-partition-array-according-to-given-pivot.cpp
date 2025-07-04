class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>res;

        for(auto &f: nums){
            if(f < pivot){
                res.push_back(f);
            }
        }

        for(auto &f: nums){
            if(f == pivot){
                res.push_back(f);
            }
        }

        for(auto &f: nums){
            if(f > pivot){
                res.push_back(f);
            }
        }


        return res;
    }
};