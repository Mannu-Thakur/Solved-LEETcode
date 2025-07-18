class Solution {
    vector<int> merging(vector<int>& nums1, vector<int>& nums2){
        vector<int>ans;
        int i=0;
        int j=0;
        int n=nums1.size();
        int m=nums2.size();
        while(i < n && j < m){
            if(nums1[i] < nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i < n ){
            ans.push_back(nums1[i]);
            i++;
        }

        while(j < m){
            ans.push_back(nums2[j]);
            j++;
        }

        return ans;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        double med = 0;
        vector<int>mergedArray(m+n);
        mergedArray = merging(nums1, nums2);
        int len = mergedArray.size();
        if( len % 2 != 0){
            med = mergedArray[len/2];
        }
        else{
            int me;
            me = mergedArray[len/2] + mergedArray[(len)/2-1];
            med = me/2.0;
        }
        return med;

    }
};

