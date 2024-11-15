class Solution {
    private:
    int solve(int idx, int buy, int transactions, vector<int> price, vector<vector<vector<int>>>& dp){
        if(idx==price.size()||transactions==0)return 0;
        if(dp[idx][buy][transactions]!=-1)return dp[idx][buy][transactions];
        if(buy){
            return dp[idx][buy][transactions]=max(-price[idx]+solve(idx+1,0,transactions,price,dp),0+solve(idx+1,1,transactions,price,dp));
        }
        else{
            return dp[idx][buy][transactions]=max(price[idx]+solve(idx+1,1,transactions-1,price,dp),0+solve(idx+1,0,transactions,price,dp));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        //Approach-1(Memoization method-Top Down dynamic programming)
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2,prices,dp);
    }
};