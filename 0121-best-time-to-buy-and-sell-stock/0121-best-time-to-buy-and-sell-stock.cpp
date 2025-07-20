class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        
        int buy = prices[0];
        int maxProfit =0;
        
        for(int i=0; i<n;++i){
              int sell = prices[i]-buy;
                maxProfit = max(maxProfit, sell);
             buy = min(buy, prices[i]);
            
        }
        return maxProfit;
    }
};