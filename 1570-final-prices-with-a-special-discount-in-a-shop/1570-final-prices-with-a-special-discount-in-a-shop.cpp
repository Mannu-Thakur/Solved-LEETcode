class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>res(prices.begin(), prices.end());
        int n = prices.size();

        for(int i=0; i<n; ++i){
        
            for(int j = i+1; j < n; ++j){
                int final = 0;
                if(prices[j] <= prices[i]){
                    final = prices[i] - prices[j];
                    res[i] = final;
                    break;
                } 
            }
        }

        return res;
    }
};