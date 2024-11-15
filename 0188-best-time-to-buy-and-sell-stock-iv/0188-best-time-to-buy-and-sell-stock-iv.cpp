class Solution {
    private:
    int solve(int idx, int buy, int transactions, vector<int> prices, vector<vector<vector<int>>>& dp){
        if(idx==prices.size()||transactions==0)return 0;
        if(dp[idx][buy][transactions]!=-1)return dp[idx][buy][transactions];
        if(buy){
            return dp[idx][buy][transactions]=max(-prices[idx]+solve(idx+1,0,transactions,prices,dp),0+solve(idx+1,1,transactions,prices,dp));
        }
        else{
            return dp[idx][buy][transactions]=max(prices[idx]+solve(idx+1,1,transactions-1,prices,dp),0+solve(idx+1,0,transactions,prices,dp));
        }
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        //Approach-1(Memoization method-Top down dynamic programming)
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,1,k,prices,dp);
    }
};