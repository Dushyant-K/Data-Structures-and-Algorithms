class Solution {
    private:
    int solve(int idx, int buy, int transactions, vector<int>& prices){
        if(idx==prices.size())return 0;

        if(buy&transactions>0){
            int profit=max(-prices[idx]+solve(idx+1,!buy,transactions,prices),0+solve(idx+1,buy,transactions,prices));
            return profit;
        }
        else if(!buy){
            int profit=max(prices[idx]+solve(idx+1,!buy,transactions-1,prices),0+solve(idx+1,buy,transactions,prices));
            return profit;
        }
        return 0;
    }
public:
    int maxProfit(vector<int>& prices) {
        //Approach-1(Memoization Method- Top Down dynamic programming)
        int n=prices.size();
        return solve(0,1,2,prices);
    }
};