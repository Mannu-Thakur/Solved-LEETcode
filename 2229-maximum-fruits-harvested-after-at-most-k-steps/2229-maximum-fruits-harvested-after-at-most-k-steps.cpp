class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();

        vector<int> prefix_amt(n);    
        prefix_amt[0] = fruits[0][1];  // amount
 
        for (int i = 1; i < n; ++i) {
            prefix_amt[i] = prefix_amt[i - 1] +  fruits[i][1];  
        }

        int i = 0;
        int j = 0;

        int ans = 0;

        while (j < n) {
            
            int leftPos = fruits[i][0];  // left position
            int rightPos = fruits[j][0]; // right position

            int left = (rightPos - leftPos) + abs(startPos - leftPos);
            int right = (rightPos - leftPos) + abs(startPos - rightPos);

            int steps =  min(left, right); 
             

             while( i <= j && steps > k){
                    i++;
                if( i <= j){
                leftPos = fruits[i][0];
                left = (rightPos - leftPos) + abs(startPos - leftPos);
                 right = (rightPos - leftPos) + abs(startPos - rightPos);

                steps =  min(left, right); 
                }
             }
            int total = prefix_amt[j] - (i > 0 ? prefix_amt[i - 1] : 0);
              ans = max(ans, total);

            j++;
        }

        return ans;
    }
};