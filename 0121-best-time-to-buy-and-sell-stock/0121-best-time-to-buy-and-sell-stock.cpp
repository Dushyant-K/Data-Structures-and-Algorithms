class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyingPrice=prices[0];
        int maxProfit = INT_MIN;
        for(int i=1;i<prices.size();i++){
            buyingPrice = min(buyingPrice,prices[i]); 
            int profit = prices[i]-buyingPrice;
            maxProfit = max(maxProfit,profit);
        }
        return maxProfit;
    }
};