class Solution {
public:
    int minOperations(int k) {
        int minOps = INT_MAX;
        if(k == 1) return 0;

        for(int a=0; a<k; ++a){
            int say = a+1;
            int b = (k +say - 1)/say - 1;
            minOps = min(minOps, a + b);
        }
        
        return minOps;
        
    }
};