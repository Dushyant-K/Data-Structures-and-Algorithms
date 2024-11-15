class Solution {
    private:
    int solve(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(idx==prices.size()){
            return 0;
        }
        if(dp[idx][buy]!=-1)return dp[idx][buy];

        if(buy){
            int profit = max(-prices[idx]+solve(idx+1,0,prices,dp),0+solve(idx+1,1,prices,dp));
            return dp[idx][buy]=profit;
        }
        else{
            int profit = max(prices[idx]+solve(idx+1,1,prices,dp),0+solve(idx+1,0,prices,dp));
            return dp[idx][buy]=profit;
        }
    }
public:
    int maxProfit(vector<int>& prices) {
      //Approach-1(Memoization Method-Top Down dynamic Programming)
    //   int n=prices.size();
    //   int buy=1;
    //   vector<vector<int>> dp(n,vector<int>(2,-1));
    //   return solve(0,buy,prices,dp);  

    //Approach-2(Tabulation Method-Bottom up dynamic programming)
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    for(int i=0;i<2;i++)dp[n][i]=0;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<2;j++){
            if(j){
            int profit = max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
            dp[i][j]=profit;
            }
            else{
            int profit = max(prices[i]+dp[i+1][1],0+dp[i+1][0]);
            dp[i][j]=profit;
        }
        }
    }
    return dp[0][1];
    }
};