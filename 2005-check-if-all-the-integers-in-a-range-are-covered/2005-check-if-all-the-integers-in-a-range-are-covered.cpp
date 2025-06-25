class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        unordered_map<int,int> a;
        for(auto i:ranges){
            for(int j=i[0];j<=i[1];j++) a[j]++;
        }
        for(int i=left;i<=right;i++){
            if(a[i]<1) return false;
        }
        return true;
    }
};