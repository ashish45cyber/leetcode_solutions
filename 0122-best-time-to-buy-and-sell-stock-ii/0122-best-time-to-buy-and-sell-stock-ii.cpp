class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       int maxprofit = 0;

       for(int i=0; i<n-1; i++){
        int j = i+1;
        if(prices[j] - prices[i] > 0){
            maxprofit += ( prices[j] - prices[i]);
        }
       } 
       return maxprofit;
    }
};